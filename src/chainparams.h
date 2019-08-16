// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2019 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_CHAINPARAMS_H
#define BITCOIN_CHAINPARAMS_H

#include "uint256.h"
#include "chainparamsbase.h"
#include "checkpoints.h"
#include "consensus/params.h"
#include "primitives/block.h"
#include "protocol.h"

#include "libzerocoin/Params.h"
#include <utility>
#include <vector>

struct CDNSSeedData {
    std::string name, host;
    CDNSSeedData(std::string  strName, std::string  strHost) : name(std::move(strName)), host(std::move(strHost)) {}
};

/**
 * CChainParams defines various tweakable parameters of a given instance of the
 * WISPR system. There are three: the main network on which people trade goods
 * and services, the public test network which gets reset from time to time and
 * a regression test mode which is intended for private networks only. It has
 * minimal difficulty to ensure that blocks can be found instantly.
 */
class CChainParams
{
public:
    enum Base58Type {
        PUBKEY_ADDRESS,
        SCRIPT_ADDRESS,
        SECRET_KEY,     // BIP16
        EXT_PUBLIC_KEY, // BIP32
        EXT_SECRET_KEY, // BIP32
        EXT_COIN_TYPE,  // BIP44

        MAX_BASE58_TYPES
    };
  const Consensus::Params& GetConsensus() const { return consensus; }
    const uint256& HashGenesisBlock() const { return consensus.hashGenesisBlock; }
  const CMessageHeader::MessageStartChars& MessageStart() const { return pchMessageStart; }
    const std::vector<unsigned char>& AlertKey() const { return vAlertPubKey; }
    int GetDefaultPort() const { return nDefaultPort; }
    const uint256& ProofOfWorkLimit() const { return consensus.powLimit; }
    const uint256& ProofOfStakeLimit() const { return consensus.stakeLimit; }
    int SubsidyHalvingInterval() const { return consensus.nSubsidyHalvingInterval; }
    /** Used to check majorities for block version upgrade */
    int EnforceBlockUpgradeMajority() const { return consensus.nEnforceBlockUpgradeMajority; }
  int RejectBlockOutdatedMajority() const { return consensus.nRejectBlockOutdatedMajority; }
  int ToCheckBlockUpgradeMajority() const { return consensus.nToCheckBlockUpgradeMajority; }

  int MaxReorganizationDepth() const { return consensus.nMaxReorganizationDepth; }
    int StakeMinAge() const { return consensus.nStakeMinAge; }
    int StakeMinAgeV2() const { return consensus.nStakeMinAgeV2; }

    /** Used if GenerateBitcoins is called with a negative number of threads */
    int DefaultMinerThreads() const { return nMinerThreads; }
    const CBlock& GenesisBlock() const { return genesis; }
    /** Make miner wait to have peers to avoid wasting work */
    bool MiningRequiresPeers() const { return fMiningRequiresPeers; }
    /** Headers first syncing is disabled */
    bool HeadersFirstSyncingActive() const { return fHeadersFirstSyncingActive; };
    /** Default value for -checkmempool and -checkblockindex argument */
    bool DefaultConsistencyChecks() const { return fDefaultConsistencyChecks; }
    /** Allow mining of a min-difficulty block */
    bool AllowMinDifficultyBlocks() const { return consensus.fAllowMinDifficultyBlocks; }
    /** Skip proof-of-work check: allow mining of any difficulty block */
    bool SkipProofOfWorkCheck() const { return consensus.fSkipProofOfWorkCheck; }
    /** Make standard checks */
    bool RequireStandard() const { return fRequireStandard; }
    int64_t TargetTimespan() const {
        return consensus.nTargetTimespanV2;
    }
    int64_t TargetSpacing() const {
        return consensus.nTargetSpacingV2;
    }
    int64_t TargetTimespanV1() const {
            return consensus.nTargetTimespanV1;
    }
    int64_t TargetSpacingV1() const {
            return consensus.nTargetSpacingV1;
    }
    int64_t IntervalV1() const {
            return consensus.nTargetTimespanV1 / consensus.nTargetSpacingV1;
        }
    int64_t TargetTimespanV2() const {
        return consensus.nTargetTimespanV2;
    }
    int64_t TargetSpacingV2() const {
        return consensus.nTargetSpacingV2;
    }
    int64_t IntervalV2() const {
        return consensus.nTargetTimespanV2 / consensus.nTargetSpacingV2;
    }
    int COINBASE_MATURITY() const { return consensus.nMaturity; }
    CAmount MaxMoneyOut() const { return consensus.nMaxMoneyOut; }
    /** The masternode count that we will allow the see-saw reward payments to be off by */
    int MasternodeCountDrift() const { return consensus.nMasternodeCountDrift; }
    /** Make miner stop after a block is found. In RPC, don't return until nGenProcLimit blocks are generated */
    bool MineBlocksOnDemand() const { return fMineBlocksOnDemand; }
    /** In the future use NetworkIDString() for RPC fields */
    bool TestnetToBeDeprecatedFieldRPC() const { return fTestnetToBeDeprecatedFieldRPC; }
    /** Return the BIP70 network string (main, test or regtest) */
    std::string NetworkIDString() const { return strNetworkID; }
    const std::vector<CDNSSeedData>& DNSSeeds() const { return vSeeds; }
    const std::vector<unsigned char>& Base58Prefix(Base58Type type) const { return base58Prefixes[type]; }
    const std::vector<CAddress>& FixedSeeds() const { return vFixedSeeds; }
    virtual const Checkpoints::CCheckpointData& Checkpoints() const = 0;
    int PoolMaxTransactions() const { return consensus.nPoolMaxTransactions; }
    /** Return the number of blocks in a budget cycle */
    int GetBudgetCycleBlocks() const { return consensus.nBudgetCycleBlocks; }
    int64_t GetProposalEstablishmentTime() const { return consensus.nProposalEstablishmentTime; }

    /** Spork key and Masternode Handling **/
    std::string SporkKey() const { return consensus.strSporkKey; }
    std::string ObfuscationPoolDummyAddress() const { return consensus.strObfuscationPoolDummyAddress; }
    int64_t StartMasternodePayments() const { return consensus.nStartMasternodePayments; }
    int64_t Budget_Fee_Confirmations() const { return consensus.nBudget_Fee_Confirmations; }

    CBaseChainParams::Network NetworkID() const { return networkID; }

    /** Zerocoin **/
    std::string Zerocoin_Modulus() const { return consensus.zerocoinModulus; }
    libzerocoin::ZerocoinParams* Zerocoin_Params(bool useModulusV1) const;
    int Zerocoin_MaxSpendsPerTransaction() const { return consensus.nMaxZerocoinSpendsPerTransaction; }
    int Zerocoin_MaxPublicSpendsPerTransaction() const { return consensus.nMaxZerocoinPublicSpendsPerTransaction; }
    CAmount Zerocoin_MintFee() const { return consensus.nMinZerocoinMintFee; }
    int Zerocoin_MintRequiredConfirmations() const { return consensus.nMintRequiredConfirmations; }
    int Zerocoin_RequiredAccumulation() const { return consensus.nRequiredAccumulation; }
    int Zerocoin_DefaultSpendSecurity() const { return consensus.nDefaultSecurityLevel; }
    int Zerocoin_HeaderVersion() const { return consensus.nZerocoinHeaderVersion; }
    int Zerocoin_RequiredStakeDepth() const { return consensus.nZerocoinRequiredStakeDepth; }

    /** Height or Time Based Activations **/
//    int ModifierUpgradeBlock() const { return nModifierUpdateBlock; }
    int Zerocoin_StartHeight() const { return consensus.nZerocoinStartHeight; }
    int Zerocoin_Block_EnforceSerialRange() const { return consensus.nBlockEnforceSerialRange; }
    int Zerocoin_Block_RecalculateAccumulators() const { return consensus.nBlockRecalculateAccumulators; }
    int Zerocoin_Block_FirstFraudulent() const { return consensus.nBlockFirstFraudulent; }
    int Zerocoin_Block_LastGoodCheckpoint() const { return consensus.nBlockLastGoodCheckpoint; }
    int Zerocoin_StartTime() const { return consensus.nZerocoinStartTime; }
    int Block_Enforce_Invalid() const { return consensus.nBlockEnforceInvalidUTXO; }
    int Zerocoin_Block_V2_Start() const { return consensus.nBlockZerocoinV2; }

    // fake serial attack
    int Zerocoin_Block_EndFakeSerial() const { return consensus.nFakeSerialBlockheightEnd; }
    CAmount GetSupplyBeforeFakeSerial() const { return consensus.nSupplyBeforeFakeSerial; }

    int Zerocoin_Block_Double_Accumulated() const { return consensus.nBlockDoubleAccumulated; }
    CAmount InvalidAmountFiltered() const { return consensus.nInvalidAmountFiltered; };
    int LAST_POW_BLOCK() const { return consensus.nLastPOWBlock; }
    int NEW_PROTOCOLS_STARTHEIGHT() const { return consensus.nNewProtocolStartHeight; }
    int NEW_PROTOCOLS_STARTTIME() const { return consensus.nNewProtocolStartTime; }
    uint32_t PivxBadBlockTime() const { return consensus.nPivxBadBlockTime; }
    uint32_t PivxBadBlocknBits() const { return consensus.nPivxBadBlocknBits; }
    int Zerocoin_Block_Public_Spend_Enabled() const { return consensus.nPublicZCSpends; }

protected:
    CChainParams() = default;

    Consensus::Params consensus;
    CMessageHeader::MessageStartChars pchMessageStart;
    //! Raw pub key bytes for the broadcast alert signing key.
    std::vector<unsigned char> vAlertPubKey;
    int nDefaultPort;
    int nMinerThreads;
    std::vector<CDNSSeedData> vSeeds;
    std::vector<unsigned char> base58Prefixes[MAX_BASE58_TYPES];
    CBaseChainParams::Network networkID;
    std::string strNetworkID;
    CBlock genesis;
    std::vector<CAddress> vFixedSeeds;
    bool fMiningRequiresPeers;
    bool fDefaultConsistencyChecks;
    bool fDefaultCheckMemPool;
    bool fRequireStandard;
    bool fMineBlocksOnDemand;
    bool fTestnetToBeDeprecatedFieldRPC;
    bool fHeadersFirstSyncingActive;
    int nPoolMaxTransactions;
    std::string strSporkKey;
    std::string strSporkKeyOld;
    int64_t nEnforceNewSporkKey;
    int64_t nRejectOldSporkKey;
    std::string strObfuscationPoolDummyAddress;
    int64_t nStartMasternodePayments;
    std::string zerocoinModulus;


};

/**
 * Modifiable parameters interface is used by test cases to adapt the parameters in order
 * to test specific features more easily. Test cases should always restore the previous
 * values after finalization.
 */

class CModifiableParams
{
public:
    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) = 0;
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) = 0;
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) = 0;
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) = 0;
    virtual void setDefaultConsistencyChecks(bool aDefaultConsistencyChecks) = 0;
    virtual void setAllowMinDifficultyBlocks(bool aAllowMinDifficultyBlocks) = 0;
    virtual void setSkipProofOfWorkCheck(bool aSkipProofOfWorkCheck) = 0;
};


/**
 * Return the currently selected parameters. This won't change after app startup
 * outside of the unit tests.
 */
const CChainParams& Params();

/** Return parameters for the given network. */
CChainParams& Params(CBaseChainParams::Network network);

/** Get modifiable network parameters (UNITTEST only) */
CModifiableParams* ModifiableParams();

/** Sets the params returned by Params() to those for the given network. */
void SelectParams(CBaseChainParams::Network network);

/**
 * Looks for -regtest or -testnet and then calls SelectParams as appropriate.
 * Returns false if an invalid combination is given.
 */
bool SelectParamsFromCommandLine();

#endif // BITCOIN_CHAINPARAMS_H
