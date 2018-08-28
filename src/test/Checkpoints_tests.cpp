// Copyright (c) 2011-2013 The Bitcoin Core developers
// Copyright (c) 2017 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "uint256.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE(Checkpoints_tests)

BOOST_AUTO_TEST_CASE(sanity) {
        uint256 p14317 = uint256("50929653a7146de37b82b9125e55ea03aa4ae062ce3a2e3098026eea07e5bc81"); // 125.000 Coin Burn Confirmation
        uint256 p50000 = uint256("b177127054381243141e809bbfb2d568aeae2dd9b3c486e54f0989d4546d0d80"); // Block 50.000
        uint256 p75000 = uint256("06f162fe22851c400c1532a6d49d7894640ea0aa292fad5f02f348480da6b20d"); // Block 75.000
        uint256 p100000 = uint256("ed8cccfb51c901af271892966160686177a05f101bd3fd517d5b82274a8f6611"); // Block 100.000
        uint256 p125000 = uint256("76d5412ec389433de6cd22345209c859b4c18b6d8f8893df479c9f7520d19901"); // Block 125.000
        uint256 p150000 = uint256("a7e0dfdc9c3197e9e763e858aafa9553c0235c0e328371a5f8c5ba0b6e44919d"); // Block 150.000
        BOOST_CHECK(Checkpoints::CheckBlock(14317, p14317));
        BOOST_CHECK(Checkpoints::CheckBlock(50000, p50000));
        BOOST_CHECK(Checkpoints::CheckBlock(75000, p75000));
        BOOST_CHECK(Checkpoints::CheckBlock(100000, p100000));
        BOOST_CHECK(Checkpoints::CheckBlock(125000, p125000));
        BOOST_CHECK(Checkpoints::CheckBlock(150000, p150000));


        // Wrong hashes at checkpoints should fail:
        BOOST_CHECK(!Checkpoints::CheckBlock(150000, p14317));
        BOOST_CHECK(!Checkpoints::CheckBlock(14317, p150000));

        // ... but any hash not at a checkpoint should succeed:
        BOOST_CHECK(Checkpoints::CheckBlock(14317 + 1, p150000));
        BOOST_CHECK(Checkpoints::CheckBlock(150000 + 1, p14317));

        BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 150000);
}

BOOST_AUTO_TEST_SUITE_END()
