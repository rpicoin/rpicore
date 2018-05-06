// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2017 The Rpicoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x14;
        pchMessageStart[1] = 0x37;
        pchMessageStart[2] = 0x25;
        pchMessageStart[3] = 0x61;
        vAlertPubKey=ParseHex("04890c0c7f2bf2304af7a7de92f3717d96b5d347e30a179cf975ab5e0152b113103598798599fecb8d735238e6dae110565d230d7ba93a076b98bd5bd5bb5f17fb");
        nDefaultPort = 18000;
        nRPCPort = 18001;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);

        const char* pszTimestamp = "Buying Bitcoin Is Not Investing, Claims Warren Buffett";
        std::vector<CTxIn> vin;
        std::vector<CTxOut> vout;

        vin.resize(1);
        vout.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        vout[0].nValue = 113713337 * COIN;
        vout[0].scriptPubKey = CScript() << ParseHex("0467b402a59fdb190a280fd7bc2234986dae22a28df82dabe19b58383c1c1f78b6d82f88fb90054efa6ff0025a8a38b802a2d04b5037f4fc56beb445f18d22d403") << OP_CHECKSIG;
        CTransaction txNew(1, 1525283223, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1525283223;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 4004610;

// uncomment to log genesis block info        
//      //  start
//        if (true && genesis.GetHash() != hashGenesisBlock)
//                       {
//                           printf("Searching for genesis block...\n");
//                           uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
//                           uint256 thash;
//
//                           while (true)
//                           {
//                               thash = genesis.GetHash();
//                               if (thash <= hashTarget)
//                                   break;
//                               if ((genesis.nNonce & 0xFFF) == 0)
//                               {
//                                   printf("nonce %08X: hash = %s (target = %s)\n", genesis.nNonce, thash.ToString().c_str(), hashTarget.ToString().c_str());
//                               }
//                               ++genesis.nNonce;
//                               if (genesis.nNonce == 0)
//                               {
//                                   printf("NONCE WRAPPED, incrementing time\n");
//                                   ++genesis.nTime;
//                               }
//                           }
//                           printf("genesis.nTime = %u \n", genesis.nTime);
//                           printf("genesis.nNonce = %u \n", genesis.nNonce);
//                           printf("genesis.nVersion = %u \n", genesis.nVersion);
//                         printf("genesis.GetHash = %s\n", genesis.GetHash().ToString().c_str()); //first this, then comment this line out and uncomment the one under.
//                           printf("genesis.hashMerkleRoot = %s \n", genesis.hashMerkleRoot.ToString().c_str()); //improvised. worked for me, to find merkle root
//
//                       }
//
        //end

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x0000b712bda549469a4533c0827bd8263299cd2d13030b15e72d93a3e094e914"));
        assert(genesis.hashMerkleRoot == uint256("0x768512611033b4e7af714b9312d1a0e529b2fb4efd9b99d406403012df093073"));

	vSeeds.push_back(CDNSSeedData("seed1.rpicoin.com", "seed1.rpicoin.com"));
        vSeeds.push_back(CDNSSeedData("seed2.rpicoin.com", "seed2.rpicoin.com"));
        vSeeds.push_back(CDNSSeedData("seed3.rpicoin.com", "seed3.rpicoin.com"));
        vSeeds.push_back(CDNSSeedData("seed4.rpicoin.com", "seed4.rpicoin.com"));
        vSeeds.push_back(CDNSSeedData("seed5.rpicoin.com", "seed5.rpicoin.com"));
        vSeeds.push_back(CDNSSeedData("seed6.rpicoin.com", "seed6.rpicoin.com"));
        vSeeds.push_back(CDNSSeedData("seed7.rpicoin.com", "seed7.rpicoin.com"));

        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 60);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 122);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, 145);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 350;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        strDataDir = "testnet";
        pchMessageStart[0] = 0x44;
        pchMessageStart[1] = 0x18;
        pchMessageStart[2] = 0x61;
        pchMessageStart[3] = 0x33;
        vAlertPubKey=ParseHex("0467b402a59fdb190a280fd7bc2234986dae22a28df82dabe19b58383c1c1f78b6d82f88fb90054efa6ff0025a8a38b802a2d04b5037f4fc56beb445f18d22d403");
        nDefaultPort = 18002;
        nRPCPort = 18003;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);

        const char* pszTimestamp = "Buying Bitcoin Is Not Investing, Claims Warren Buffett";
        std::vector<CTxIn> vin;
        std::vector<CTxOut> vout;

        vin.resize(1);
        vout.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        vout[0].SetEmpty();
        
        CTransaction txNew(1, 1525283445, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1525283445;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 1759192;

 // uncomment to log genesis block info        
      //  start
  //      if (true && genesis.GetHash() != hashGenesisBlock)
        //               {
      //                     printf("Searching for genesis block...\n");
    //                       uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
  //                         uint256 thash;
//
                    //       while (true)
                  //         {
                //               thash = genesis.GetHash();
              //                 if (thash <= hashTarget)
            //                       break;
          //                     if ((genesis.nNonce & 0xFFF) == 0)
        //                       {
      //                             printf("nonce %08X: hash = %s (target = %s)\n", genesis.nNonce, thash.ToString().c_str(), hashTarget.ToString().c_str());
    //                           }
   //                            ++genesis.nNonce;
                //               if (genesis.nNonce == 0)
              //                 {
              //                     printf("NONCE WRAPPED, incrementing time\n");
            //                       ++genesis.nTime;
          //                     }
        //                   }
      //                     printf("genesis.nTime = %u \n", genesis.nTime);
    //                       printf("genesis.nNonce = %u \n", genesis.nNonce);
  //                         printf("genesis.nVersion = %u \n", genesis.nVersion);
//                         printf("genesis.GetHash = %s\n", genesis.GetHash().ToString().c_str()); //first this, then comment this line out and uncomment the one under.
//                           printf("genesis.hashMerkleRoot = %s \n", genesis.hashMerkleRoot.ToString().c_str()); //improvised. worked for me, to find merkle root

  //                     }
//
        //end

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x0000d17194220e485dce46951ad042de557ceefdcdc96b1a4358847c103f9aae"));
        assert(genesis.hashMerkleRoot == uint256("0x25533f4208eab0dd0e880a32df9405daff31850bd23d2ec9dd7db8532992cb88"));

        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 110);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 8);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 239);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 350;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xAD;
        pchMessageStart[1] = 0xBF;
        pchMessageStart[2] = 0xB1;
        pchMessageStart[3] = 0xDA;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1411111111;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 2;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18004;
        strDataDir = "regtest";
        //assert(hashGenesisBlock == uint256("0x523dda6d336047722cbaf1c5dce622298af791bac21b33bf6e2d5048b2a13e3d"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
