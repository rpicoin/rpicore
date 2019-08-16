// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2019 The PIVX developers
// Copyright (c) 2018-2019 The WISPR developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>


struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
                (0, uint256("0x0000b712bda549469a4533c0827bd8263299cd2d13030b15e72d93a3e094e914"))
                (50000, uint256("e13891ed03b98324162082f47ae4dd4250a075ae9a96f982961e284aa83259b5")) // Block 50.000
                (100000, uint256("c26704a2af85d7da0c4e15a7a6e7648f87e4dd15512fb4586d04fc5ec0b01211")) // Block 100.000
                (150000, uint256("69c550f21163c0f0c4bbb07184c7d178f0d372048a8bd1e52473517c33b87b3f")) // Block 150.000
                (200000, uint256("ffb7f3996cd225fa8e106117ec7e428a2e8db4f3e76e8c03b24c36ade5ecddd2")) // Block 200.000
                (250000, uint256("149cd7201a2978fea3ee0f098ab8f989b1b9436f2cc8cebf45986ff9aaad3ca1")) // Block 250.000
                (300000, uint256("a4379a7772bda6a59d7a03b59da3168585d97e9ece9906c327cbc07307169fff")) // Block 300.000
                (350000, uint256("fd0c691aad1762436b65939c0cc60df87d6b95397047c55f718c1831d75aa1bb")) // Block 350.000
                (400000, uint256("970dfe35eaeb3a3c0339fcb28800b669341e8ca61f2da3aac11a9253896bd669")) // Block 400.000
                (450000, uint256("05db87a93a517a551a68417a9ac21854e5a899ea8895d890639486a8a23e1a35")) // Block 450.000
                (500000, uint256("8263684c3f6f957babcff5f9d793b6b1e9129b8f10a67ca769e6ce5fd3c2dbd4")) // Block 500.000
                (550000, uint256("0d8789b2fa1e90ae584635b1d4945d80394678096291c9b16e387ab4a16c9abf")) // Block 550.000
                (600000, uint256("82485a51346003316f4ad962e1999e313fb0094e8cbc5893a82e57cb7ac2d62a")); // Block 550.000
static const Checkpoints::CCheckpointData data = {
        &mapCheckpoints,
        1565931910, // * UNIX timestamp of last checkpoint block (Done)
        1232063,    // * total number of transactions between genesis and last checkpoint TODO: keep using correct number
        //   (the tx=... number in the SetBestChain debug.log lines)
        2000        // * estimated number of transactions per day after checkpoint
};


static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        1512932225,
        0,
        450};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
        boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
        &mapCheckpointsRegtest,
        1411111111,
        0,
        100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const
{
    assert(this);
    static CBigNum bnHexModulus = 0;
    if (!bnHexModulus)
        bnHexModulus.SetHex(consensus.zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus);
    static CBigNum bnDecModulus = 0;
    if (!bnDecModulus)
        bnDecModulus.SetDec(consensus.zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);

    if (useModulusV1)
        return &ZCParamsHex;

    return &ZCParamsDec;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 0;
        consensus.nEnforceBlockUpgradeMajority = 750;
        consensus.nRejectBlockOutdatedMajority = 950;
        consensus.nToCheckBlockUpgradeMajority = 1000;
        consensus.nMaxReorganizationDepth = 500;
        consensus.powLimit = ~uint256(0) >> 16; // RPICOIN starting difficulty is 1 / 2^12
        consensus.stakeLimit = ~uint256(0) >> 48;
        consensus.nTargetTimespanV1 =  16 * 60; // RPICOIN Old: 1 day
        consensus.nTargetTimespanV2 =  1 * 60; // RPICOIN New: 1 day
        consensus.nTargetSpacingV1 = 64;  // RPICOIN Old: 1 minute
        consensus.nTargetSpacingV2 = 1 * 60;  // RPICOIN New: 1 minute
        consensus.nMaturity = 10;
        consensus.nMasternodeCountDrift = 20;
        consensus.nMaxMoneyOut = 5999991337 * COIN;
        /** Height or Time Based Activations **/
        consensus.nLastPOWBlock = 100;
        consensus.nNewProtocolStartHeight = 600000;
        consensus.nNewProtocolStartTime = 1564511361; //Tuesday, July 30, 2019 18:29:21 PM #NOT USED
        consensus.nZerocoinStartHeight = consensus.nNewProtocolStartHeight;
        consensus.nZerocoinStartTime = consensus.nNewProtocolStartTime;

        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x14;
        pchMessageStart[1] = 0x37;
        pchMessageStart[2] = 0x25;
        pchMessageStart[3] = 0x61;
        vAlertPubKey=ParseHex("04890c0c7f2bf2304af7a7de92f3717d96b5d347e30a179cf975ab5e0152b113103598798599fecb8d735238e6dae110565d230d7ba93a076b98bd5bd5bb5f17fb");
        nDefaultPort = 18000;
        nMinerThreads = 0;
        consensus.nBlockDoubleAccumulated = -1;
        consensus.nBlockEnforceSerialRange = consensus.nNewProtocolStartHeight; //Enforce serial range starting this block
        consensus.nBlockRecalculateAccumulators = consensus.nNewProtocolStartHeight; //Trigger a recalculation of accumulators
        consensus.nBlockFirstFraudulent = -1; //First block that bad serials emerged
        consensus.nBlockLastGoodCheckpoint = consensus.nNewProtocolStartHeight; //Last valid accumulator checkpoint
        consensus.nPivxBadBlockTime = 0; // Skip nBit validation of Block 259201 per PR #915
        consensus.nPivxBadBlocknBits = 0; // Skip nBit validation of Block 259201 per PR #915
        consensus.nStakeMinAge = 4 * 60 * 60;
        consensus.nStakeMinAgeV2 = 60 * 60;   // PIVX: 1 hour

        // Public coin spend enforcement
        consensus.nPublicZCSpends = 600000;

        // Fake Serial Attack
        consensus.nFakeSerialBlockheightEnd = -1;
        consensus.nSupplyBeforeFakeSerial = 0;   // zerocoin supply at block nFakeSerialBlockheightEnd

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "Buying Bitcoin Is Not Investing, Claims Warren Buffett";
        CMutableTransaction txNew;
        txNew.nVersion = 1;
        txNew.nTime = 1525283223;
        txNew.nLockTime = 0;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 0 << CScriptNum(42) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 113713337 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("0467b402a59fdb190a280fd7bc2234986dae22a28df82dabe19b58383c1c1f78b6d82f88fb90054efa6ff0025a8a38b802a2d04b5037f4fc56beb445f18d22d403") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1525283223;
        genesis.nBits = consensus.powLimit.GetCompact();
        genesis.nNonce = 4004610;

        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256("0x0000b712bda549469a4533c0827bd8263299cd2d13030b15e72d93a3e094e914"));
        assert(genesis.hashMerkleRoot == uint256("0x768512611033b4e7af714b9312d1a0e529b2fb4efd9b99d406403012df093073"));

        vSeeds.push_back(CDNSSeedData("seed1.rpicoin.com", "seed1.rpicoin.com"));
        vSeeds.push_back(CDNSSeedData("seed2.rpicoin.com", "seed2.rpicoin.com"));
        vSeeds.push_back(CDNSSeedData("seed3.rpicoin.com", "seed3.rpicoin.com"));
        vSeeds.push_back(CDNSSeedData("seed4.rpicoin.com", "seed4.rpicoin.com"));
        vSeeds.push_back(CDNSSeedData("seed5.rpicoin.com", "seed5.rpicoin.com"));
        vSeeds.push_back(CDNSSeedData("seed6.rpicoin.com", "seed6.rpicoin.com"));
        vSeeds.push_back(CDNSSeedData("seed7.rpicoin.com", "seed7.rpicoin.com"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 60);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 122);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 145);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        consensus.fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fDefaultCheckMemPool = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        consensus.fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        consensus.nPoolMaxTransactions = 3;
        consensus.nBudgetCycleBlocks = 43200; //!< Amount of blocks in a months period of time (using 1 minutes per) = (60*24*30)
        consensus.strSporkKey = "042ebd54696c8118a15522c1a755845ce3eab63ab3f655533bb16660539278788ae0221e0ea3fd96a5def1d3707672561a319d2b1a7b07b9139c1846aea406b338";
        consensus.strObfuscationPoolDummyAddress = "RJqgPMnzYPpwwctE1cXC691dC7EuqFAHZW ";
        consensus.nStartMasternodePayments = consensus.nNewProtocolStartTime; // July 2, 2018

        /** Zerocoin */
        consensus.zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
                          "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
                          "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
                          "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
                          "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
                          "31438167899885040445364023527381951378636564391212010397122822120720357";
        consensus.nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        consensus.nMaxZerocoinPublicSpendsPerTransaction = 637; // Assume about 220 bytes each input
        consensus.nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        consensus.nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        consensus.nRequiredAccumulation = 1;
        consensus.nDefaultSecurityLevel = 100; //full security level for accumulators
        consensus.nZerocoinHeaderVersion = 8; //Block headers must be this version once zerocoin is active
        consensus.nZerocoinRequiredStakeDepth = 200; //The required confirmations for a zrpi to be stakable

        consensus.nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
        consensus.nProposalEstablishmentTime = 60 * 60 * 24; // Proposals must be at least a day old to make it into a budget
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        consensus.nSubsidyHalvingInterval = 0;
        consensus.nEnforceBlockUpgradeMajority = 51;
        consensus.nRejectBlockOutdatedMajority = 75;
        consensus.nToCheckBlockUpgradeMajority = 100;
        consensus.nMaxReorganizationDepth = 500;
        consensus.powLimit = ~uint256(0) >> 16; // RPICOIN starting difficulty is 1 / 2^12
        consensus.stakeLimit = ~uint256(0) >> 48;
        consensus.nTargetTimespanV1 =  16 * 60; // RPICOIN Old: 1 day
        consensus.nTargetTimespanV2 =  1 * 60; // RPICOIN New: 1 day
        consensus.nTargetSpacingV1 = 64;  // RPICOIN Old: 1 minute
        consensus.nTargetSpacingV2 = 1 * 60;  // RPICOIN New: 1 minute
        consensus.nLastPOWBlock = 100;
        consensus.nMaturity = 10;
        consensus.nMasternodeCountDrift = 4;
        consensus.nMaxMoneyOut = 5999991337 * COIN;
        consensus.nNewProtocolStartHeight = 750;
        consensus.nNewProtocolStartTime = 1537830552;
        consensus.nZerocoinStartHeight = consensus.nNewProtocolStartHeight;
        consensus.nZerocoinStartTime = consensus.nNewProtocolStartTime; // July 2, 2018
        consensus.nPivxBadBlockTime = 0; // Skip nBit validation of Block 259201 per PR #915
        consensus.nPivxBadBlocknBits = 0; // Skip nBit validation of Block 201 per PR #915

        pchMessageStart[0] = 0x44;
        pchMessageStart[1] = 0x18;
        pchMessageStart[2] = 0x61;
        pchMessageStart[3] = 0x33;
        vAlertPubKey=ParseHex("0467b402a59fdb190a280fd7bc2234986dae22a28df82dabe19b58383c1c1f78b6d82f88fb90054efa6ff0025a8a38b802a2d04b5037f4fc56beb445f18d22d403");
        nDefaultPort = 18002;
        nMinerThreads = 0;

        const char* pszTimestamp = "Buying Bitcoin Is Not Investing, Claims Warren Buffett";
        genesis.SetNull();
        CMutableTransaction txNew2;
        txNew2.nVersion = 1;
        txNew2.nTime = 1525283445;
        txNew2.nLockTime = 0;
        txNew2.vin.resize(1);
        txNew2.vout.resize(1);
        txNew2.vin[0].scriptSig = CScript() << 0 << CScriptNum(42) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew2.vout[0].SetEmpty();

        // Public coin spend enforcement
        consensus.nPublicZCSpends = 1106100;

        // Fake Serial Attack
        consensus.nFakeSerialBlockheightEnd = -1;
        consensus.nSupplyBeforeFakeSerial = 0;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.vtx.push_back(txNew2);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1525283445;
        genesis.nBits    = consensus.powLimit.GetCompact();
        genesis.nNonce   = 1759192;

        consensus.hashGenesisBlock = genesis.GetHash();

        assert(consensus.hashGenesisBlock == uint256("0x0000d17194220e485dce46951ad042de557ceefdcdc96b1a4358847c103f9aae"));
        assert(genesis.hashMerkleRoot == uint256("0x25533f4208eab0dd0e880a32df9405daff31850bd23d2ec9dd7db8532992cb88"));


        vFixedSeeds.clear();
        vSeeds.clear();


        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 110);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 8);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 239);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        consensus.fSkipProofOfWorkCheck = false;
        fMiningRequiresPeers = true;
        consensus.fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fDefaultCheckMemPool = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        consensus.nPoolMaxTransactions = 2;
        consensus.nBudgetCycleBlocks = 144; //!< Ten cycles per day on testnet
        consensus.strSporkKey = "04e175173ea919f973cf4bf00d10e1c29c8ef75568c59056630d5a5cce8f6d8ac6edf0bb21baa2a24ecff17ce83b9863a88a54c54ca87c709c8a3f1dfef9d268e6";
        consensus.strObfuscationPoolDummyAddress = "mbTYaNZm7TaPt5Du65aPsL8FNTktufYydC";
        consensus.nStartMasternodePayments = consensus.nNewProtocolStartTime;
        consensus.nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
        // here because we only have a 8 block finalization window on testnet
        consensus.nProposalEstablishmentTime = 60 * 5; // Proposals must be at least 5 mns old to make it into a test budget

    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        consensus.nSubsidyHalvingInterval = 0;
        consensus.nEnforceBlockUpgradeMajority = 750;
        consensus.nRejectBlockOutdatedMajority = 950;
        consensus.nToCheckBlockUpgradeMajority = 1000;
        consensus.nMaxReorganizationDepth = 500;
        consensus.powLimit = ~uint256(0) >> 1; // RPICOIN starting difficulty is 1 / 2^12
        consensus.stakeLimit = ~uint256(0) >> 48;
        consensus.nLastPOWBlock = 250;
        consensus.nTargetTimespanV1 = 16 * 60; // RPICOIN Old: 1 day
        consensus.nTargetTimespanV2 = 1 * 60; // RPICOIN New: 1 day
        consensus.nTargetSpacingV1 = 64;        // RPICOIN Old: 1 minutes
        consensus.nTargetSpacingV2 = 1 * 60;        // RPICOIN New: 1 minute
        consensus.nNewProtocolStartHeight = 300;
        consensus.nStakeMinAge = 0;
        consensus.nStakeMinAgeV2 = 0;

        consensus.nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        consensus.nBlockRecalculateAccumulators = 999999999; //Trigger a recalculation of accumulators
        consensus.nBlockFirstFraudulent = 999999999; //First block that bad serials emerged
        consensus.nBlockLastGoodCheckpoint = 999999999; //Last valid accumulator checkpoint

        // Public coin spend enforcement
        consensus.nPublicZCSpends = 350;

        // Fake Serial Attack
        consensus.nFakeSerialBlockheightEnd = -1;

        pchMessageStart[0] = 0xAD;
        pchMessageStart[1] = 0xBF;
        pchMessageStart[2] = 0xB1;
        pchMessageStart[3] = 0xDA;
        nMinerThreads = 1;
        genesis.nTime = 1411111111;
        genesis.nBits  = consensus.powLimit.GetCompact();
        genesis.nNonce = 2;

        consensus.hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18004;
//        printf("Req net\n");
//        printf("genesis = %s\n", genesis.ToString().c_str());
        assert(consensus.hashGenesisBlock == uint256("6bc08d74ce7ed1003efdb1eb6a28b1a2e283f9486664be37fee7ea9d1ece6be1"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        consensus.fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fDefaultCheckMemPool = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        consensus.fSkipProofOfWorkCheck = true;
        fTestnetToBeDeprecatedFieldRPC = false;

        /* Spork Key for RegTest:
        WIF private key: 932HEevBSujW2ud7RfB1YF91AFygbBRQj3de3LyaCRqNzKKgWXi
        private key hex: bd4960dcbd9e7f2223f24e7164ecb6f1fe96fc3a416f5d3a830ba5720c84b8ca
        Address: yCvUVd72w7xpimf981m114FSFbmAmne7j9
        */
        consensus.strSporkKey = "02161ea61cdeacc91ac87728a98966b6e6ebda46c50644d954e03a6ba5426a78d5";
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 18005;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        consensus.fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { consensus.nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { consensus.nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { consensus.nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { consensus.nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { consensus.fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { consensus.fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = nullptr;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
        case CBaseChainParams::MAIN:
            return mainParams;
        case CBaseChainParams::TESTNET:
            return testNetParams;
        case CBaseChainParams::REGTEST:
            return regTestParams;
        case CBaseChainParams::UNITTEST:
            return unitTestParams;
        default:
            assert(false && "Unimplemented network");
            return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
