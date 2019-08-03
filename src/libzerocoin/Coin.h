/**
 * @file       Coin.h
 *
 * @brief      libzerocoin::PublicCoin and PrivateCoin classes for the Zerocoin library.
 *
 * @author     Ian Miers, Christina Garman and Matthew Green
 * @date       June 2013
 *
 * @copyright  Copyright 2013 Ian Miers, Christina Garman and Matthew Green
 * @license    This project is released under the MIT license.
 **/
// Copyright (c) 2017-2019 The PIVX developers

#ifndef COIN_H_
#define COIN_H_
#include "Denominations.h"
#include "Params.h"
#include "amount.h"
#include "bignum.h"
#include "util.h"
#include "key.h"

namespace libzerocoin
{

    class InvalidSerialException : public std::exception {
    public:
        std::string message;
        InvalidSerialException(const std::string &message) : message(message) {}
    };

    int ExtractVersionFromSerial(const CBigNum& bnSerial);
    bool IsValidSerial(const libzerocoin::ZerocoinParams* params, const CBigNum& bnSerial);
    bool IsValidCommitmentToCoinRange(const libzerocoin::ZerocoinParams* params, const CBigNum& bnCommitment);
    CBigNum GetAdjustedSerial(const CBigNum& bnSerial);
    bool GenerateKeyPair(const CBigNum& bnGroupOrder, const uint256& nPrivkey, CKey& key, CBigNum& bnSerial);

/** A Public coin is the part of a coin that
 * is published to the network and what is handled
 * by other clients. It contains only the value
 * of commitment to a serial number and the
 * denomination of the coin.
 */
class PublicCoin
{
public:
    template <typename Stream>
    PublicCoin(const libzerocoin::ZerocoinParams* p, Stream& strm) : params(p)
    {
        strm >> *this;
    }

    PublicCoin(const libzerocoin::ZerocoinParams* p);

    /**Generates a public coin
	 *
	 * @param p cryptographic paramters
	 * @param coin the value of the commitment.
	 * @param denomination The denomination of the coin. 
	 */
    PublicCoin(const libzerocoin::ZerocoinParams* p, const CBigNum& coin, const libzerocoin::CoinDenomination d);
    const CBigNum& getValue() const { return this->value; }

    libzerocoin::CoinDenomination getDenomination() const { return this->denomination; }
    bool operator==(const libzerocoin::PublicCoin& rhs) const
    {
        return ((this->value == rhs.value) && (this->params == rhs.params) && (this->denomination == rhs.denomination));
    }
    bool operator!=(const libzerocoin::PublicCoin& rhs) const { return !(*this == rhs); }
    /** Checks that coin is prime and in the appropriate range given the parameters
     * @return true if valid
     */
    bool validate() const;

    ADD_SERIALIZE_METHODS;
    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion)
    {
        READWRITE(value);
        READWRITE(denomination);
    }

private:
    const libzerocoin::ZerocoinParams* params;
    CBigNum value;
    libzerocoin::CoinDenomination denomination;
};

/**
 * A private coin. As the name implies, the content
 * of this should stay private except PublicCoin.
 *
 * Contains a coin's serial number, a commitment to it,
 * and opening randomness for the commitment.
 *
 * @warning Failure to keep this secret(or safe),
 * @warning will result in the theft of your coins
 * @warning and a TOTAL loss of anonymity.
 */
class PrivateCoin
{
public:
    static int const PUBKEY_VERSION = 2;
    static int const CURRENT_VERSION = 2;
    static int const V2_BITSHIFT = 4;
    template <typename Stream>
    PrivateCoin(const libzerocoin::ZerocoinParams* p, Stream& strm) : params(p), publicCoin(p)
    {
        strm >> *this;
    }
    PrivateCoin(const libzerocoin::ZerocoinParams* p, const libzerocoin::CoinDenomination denomination, bool fMintNew = true);
    PrivateCoin(const libzerocoin::ZerocoinParams* p, const libzerocoin::CoinDenomination denomination, const CBigNum& bnSerial, const CBigNum& bnRandomness);
    const libzerocoin::PublicCoin& getPublicCoin() const { return this->publicCoin; }
    // @return the coins serial number
    const CBigNum& getSerialNumber() const { return this->serialNumber; }
    const CBigNum& getRandomness() const { return this->randomness; }
    const CPrivKey& getPrivKey() const { return this->privkey; }
    const CPubKey getPubKey() const;
    const uint8_t& getVersion() const { return this->version; }

    void setPublicCoin(PublicCoin p) { publicCoin = p; }
    void setRandomness(CBigNum n) { randomness = n; }
    void setSerialNumber(CBigNum n) { serialNumber = n; }
    void setVersion(uint8_t nVersion) { this->version = nVersion; }
    void setPrivKey(const CPrivKey& privkey) { this->privkey = privkey; }
    bool sign(const uint256& hash, std::vector<unsigned char>& vchSig) const;
    bool IsValid();

    ADD_SERIALIZE_METHODS;
    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion)
    {
        READWRITE(publicCoin);
        READWRITE(randomness);
        READWRITE(serialNumber);
        version = (uint8_t )ExtractVersionFromSerial(serialNumber);
        if (version == 2) {
            READWRITE(version);
            READWRITE(privkey);
        }
    }

private:
    const libzerocoin::ZerocoinParams* params;
    libzerocoin::PublicCoin publicCoin;
    CBigNum randomness;
    CBigNum serialNumber;
    uint8_t version = 1;
    CPrivKey privkey;

    /**
	 * @brief Mint a new coin.
	 * @param denomination the denomination of the coin to mint
	 * @throws ZerocoinException if the process takes too long
	 *
	 * Generates a new Zerocoin by (a) selecting a random serial
	 * number, (b) committing to this serial number and repeating until
	 * the resulting commitment is prime. Stores the
	 * resulting commitment (coin) and randomness (trapdoor).
	 **/
    void mintCoin(const libzerocoin::CoinDenomination denomination);

    /**
	 * @brief Mint a new coin using a faster process.
	 * @param denomination the denomination of the coin to mint
	 * @throws ZerocoinException if the process takes too long
	 *
	 * Generates a new Zerocoin by (a) selecting a random serial
	 * number, (b) committing to this serial number and repeating until
	 * the resulting commitment is prime. Stores the
	 * resulting commitment (coin) and randomness (trapdoor).
	 * This routine is substantially faster than the
	 * mintCoin() routine, but could be more vulnerable
	 * to timing attacks. Don't use it if you think someone
	 * could be timing your coin minting.
	 **/
    void mintCoinFast(const libzerocoin::CoinDenomination denomination);
};

} /* namespace libzerocoin */
#endif /* COIN_H_ */
