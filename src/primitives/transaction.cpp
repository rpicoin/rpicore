// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2015-2019 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/block.h"
#include "primitives/transaction.h"

#include "chain.h"
#include "hash.h"
#include "main.h"
#include "tinyformat.h"
#include "utilstrencodings.h"
#include "transaction.h"

#include <utility>


extern bool GetTransaction(const uint256 &hash, CTransaction &txOut, uint256 &hashBlock, bool fAllowSlow);

std::string COutPoint::ToString() const
{
    return strprintf("COutPoint(%s, %u)", hash.ToString()/*.substr(0,10)*/, n);
}

std::string COutPoint::ToStringShort() const
{
    return strprintf("%s-%u", hash.ToString().substr(0,64), n);
}

uint256 COutPoint::GetHash()
{
    return Hash(BEGIN(hash), END(hash), BEGIN(n), END(n));
}

CTxIn::CTxIn(const COutPoint& prevoutIn, const CScript& scriptSigIn, uint32_t nSequenceIn)
{
    prevout = std::move(prevoutIn);
    scriptSig = scriptSigIn;
    nSequence = nSequenceIn;
}

CTxIn::CTxIn(const uint256& hashPrevTx, uint32_t nOut, const CScript& scriptSigIn, uint32_t nSequenceIn)
{
    prevout = COutPoint(std::move(hashPrevTx), nOut);
    scriptSig = scriptSigIn;
    nSequence = nSequenceIn;
}

CTxIn::CTxIn(const libzerocoin::CoinSpend& spend, libzerocoin::CoinDenomination denom)
{
    //Serialize the coinspend object and append it to a CScript
    CDataStream serializedCoinSpend(SER_NETWORK, PROTOCOL_VERSION);
    serializedCoinSpend << spend;
    std::vector<unsigned char> data(serializedCoinSpend.begin(), serializedCoinSpend.end());

    scriptSig = CScript() << OP_ZEROCOINSPEND << data.size();
    scriptSig.insert(scriptSig.end(), data.begin(), data.end());
    prevout.SetNull();
    nSequence = denom;
}

bool CTxIn::IsZerocoinSpend() const
{
    return prevout.hash == 0 && scriptSig.IsZerocoinSpend();
}

bool CTxIn::IsZerocoinPublicSpend() const
{
    return scriptSig.IsZerocoinPublicSpend();
}

std::string CTxIn::ToString() const
{
    std::string str;
    str += "CTxIn(";
    str += prevout.ToString();
    str += strprintf(", hash=%s", GetHash().ToString());
    str += strprintf(", prevPubKey=%s", prevPubKey.ToString());
    str += strprintf(", nSequence=%u", nSequence);
    if (prevout.IsNull())
        if(IsZerocoinSpend())
            str += strprintf(", zerocoinspend %s...", HexStr(scriptSig).substr(0, 25));
        else
            str += strprintf(", coinbase %s", HexStr(scriptSig));
    else
        str += strprintf(", scriptSig=%s", scriptSig.ToString());
    if (nSequence != std::numeric_limits<unsigned int>::max())
        str += strprintf(", nSequence=%u", nSequence);
    str += ")";
    return str;
}

CTxOut::CTxOut(const CAmount& nValueIn, const CScript& scriptPubKeyIn)
{
    nValue = nValueIn;
    scriptPubKey = scriptPubKeyIn;
    nRounds = -10;
}

bool COutPoint::IsMasternodeReward(const CTransaction* tx) const
{
    if(!tx->IsCoinStake())
        return false;

    return (n == tx->vout.size() - 1) && (tx->vout[1].scriptPubKey != tx->vout[n].scriptPubKey);
}

uint256 CTxOut::GetHash() const
{
    return SerializeHash(*this);
}

uint256 CTxIn::GetHash() const {
    return SerializeHash(*this);
}

bool CTxOut::IsZerocoinMint() const
{
    return scriptPubKey.IsZerocoinMint();
}

CAmount CTxOut::GetZerocoinMinted() const
{
    if (!IsZerocoinMint())
        return CAmount(0);

    return nValue;
}

std::string CTxOut::ToString() const
{
    return strprintf("CTxOut(nValue=%d.%08d, scriptPubKey=%s, nRounds=%u, hash=%s)",
                     nValue / COIN,
                     nValue % COIN,
                     scriptPubKey.ToString(),
                     nRounds,
                     GetHash().ToString());
}

CMutableTransaction::CMutableTransaction() : nVersion(CTransaction::CURRENT_VERSION), nTime(GetAdjustedTime()), nLockTime(0) {}
CMutableTransaction::CMutableTransaction(const CTransaction& tx) : nVersion(tx.nVersion), nTime(tx.nTime), vin(tx.vin), vout(tx.vout), nLockTime(tx.nLockTime) {}

uint256 CMutableTransaction::GetHash() const
{
    return SerializeHash(*this);
}

std::string CMutableTransaction::ToString() const
{
    std::string str;
    str += strprintf("CMutableTransaction(ver=%d, vin.size=%u, vout.size=%u, nLockTime=%u)\n",
        nVersion,
        vin.size(),
        vout.size(),
        nLockTime);
    for (const auto & i : vin){
        str += "    " + i.ToString() + "\n";
    }
    for (const auto & i : vout){
        str += "    " + i.ToString() + "\n";
    }
    return str;
}

uint256 CTransaction::ComputeHash() const
{
    return SerializeHash(*this);
}

CTransaction::CTransaction() : nVersion(CTransaction::CURRENT_VERSION), nTime(GetAdjustedTime()), vin(), vout(), nLockTime(0), hash{} { }

CTransaction::CTransaction(const CMutableTransaction &tx) : nVersion(tx.nVersion), nTime(tx.nTime), vin(tx.vin), vout(tx.vout), nLockTime(tx.nLockTime), hash{ComputeHash()} {}

CTransaction &CTransaction::operator=(const CTransaction &tx) {
    *const_cast<int32_t *>(&nVersion) = tx.nVersion;
    *const_cast<unsigned int *>(&nTime) = tx.nTime;
    *const_cast<std::vector <CTxIn> *>(&vin) = tx.vin;
    *const_cast<std::vector <CTxOut> *>(&vout) = tx.vout;
    *const_cast<uint32_t *>(&nLockTime) = tx.nLockTime;
    *const_cast<uint256 *>(&hash) = tx.hash;
    return *this;
}

bool CTransaction::HasZerocoinSpendInputs() const
{
    for (const CTxIn& txin: vin) {
        if (txin.IsZerocoinSpend() || txin.IsZerocoinPublicSpend())
            return true;
    }
    return false;
}

bool CTransaction::HasZerocoinMintOutputs() const
{
    for(const CTxOut& txout : vout) {
        if (txout.IsZerocoinMint())
            return true;
    }
    return false;
}

bool CTransaction::HasZerocoinPublicSpendInputs() const
{
    // The wallet only allows publicSpend inputs in the same tx and not a combination between piv and zwsp
    for(const CTxIn& txin : vin) {
        if (txin.IsZerocoinPublicSpend())
            return true;
    }
    return false;
}

bool CTransaction::IsCoinStake() const
{
    if (vin.empty())
        return false;

    // ppcoin: the coin stake transaction is marked with the first output empty
    bool fAllowNull = vin[0].IsZerocoinSpend();
    if (vin[0].prevout.IsNull() && !fAllowNull)
        return false;

    return (vout.size() >= 2 && vout[0].IsEmpty());
}

CAmount CTransaction::GetValueOut() const
{
    CAmount nValueOut = 0;
    for (const auto & it : vout)
    {
        // WISPR: previously MoneyRange() was called here. This has been replaced with negative check and boundary wrap check.
        if (it.nValue < 0)
            throw std::runtime_error("CTransaction::GetValueOut() : value out of range : less than 0");

        if ((nValueOut + it.nValue) < nValueOut)
            throw std::runtime_error("CTransaction::GetValueOut() : value out of range : wraps the int64_t boundary");

        nValueOut += it.nValue;
    }
    return nValueOut;
}

CAmount CTransaction::GetZerocoinMinted() const
{
    CAmount nValueOut = 0;
    for (const CTxOut& txOut : vout) {
        nValueOut += txOut.GetZerocoinMinted();
    }

    return  nValueOut;
}

bool CTransaction::UsesUTXO(const COutPoint& out)
{
    for (const CTxIn& in : vin) {
        if (in.prevout == out)
            return true;
    }

    return false;
}

std::list<COutPoint> CTransaction::GetOutPoints() const
{
    std::list<COutPoint> listOutPoints;
    uint256 txHash = GetHash();
    for (unsigned int i = 0; i < vout.size(); i++){
        listOutPoints.emplace_back(COutPoint(txHash, i));
    }
    return listOutPoints;
}

CAmount CTransaction::GetZerocoinSpent() const
{
    CAmount nValueOut = 0;
    for (const CTxIn& txin : vin) {
        if(!txin.IsZerocoinSpend())
            continue;

        nValueOut += txin.nSequence * COIN;
    }

    return nValueOut;
}

int CTransaction::GetZerocoinMintCount() const
{
    int nCount = 0;
    for (const CTxOut& out : vout) {
        if (out.IsZerocoinMint())
            nCount++;
    }
    return nCount;
}

double CTransaction::ComputePriority(double dPriorityInputs, unsigned int nTxSize) const
{
    nTxSize = CalculateModifiedSize(nTxSize);
    if (nTxSize == 0) return 0.0;

    return dPriorityInputs / nTxSize;
}

unsigned int CTransaction::CalculateModifiedSize(unsigned int nTxSize) const
{
    // In order to avoid disincentivizing cleaning up the UTXO set we don't count
    // the constant overhead for each txin and up to 110 bytes of scriptSig (which
    // is enough to cover a compressed pubkey p2sh redemption) for priority.
    // Providing any more cleanup incentive than making additional inputs free would
    // risk encouraging people to create junk outputs to redeem later.
    if (nTxSize == 0)
        nTxSize = ::GetSerializeSize(*this, SER_NETWORK, PROTOCOL_VERSION);
    for (const auto & it : vin)
    {
        unsigned int offset = 41U + std::min(110U, (unsigned int)it.scriptSig.size());
        if (nTxSize > offset)
            nTxSize -= offset;
    }
    return nTxSize;
}

std::string CTransaction::ToString() const
{
    std::string str;
    str += strprintf("CTransaction(hash=%s, ver=%d, vin.size=%u, vout.size=%u, nLockTime=%u, nTime=%u)\n",
                     GetHash().ToString(),
                     nVersion,
                     vin.size(),
                     vout.size(),
                     nLockTime,
                     nTime);
    for (const auto & i : vin){
        str += "    " + i.ToString() + "\n";
    }
    for (const auto & i : vout){
        str += "    " + i.ToString() + "\n";
    }
    return str;
}
