// Copyright (c) 2011-2013 The Bitcoin Core developers
// Copyright (c) 2017-2018 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//
// Unit tests for block-chain checkpoints
//

#include "checkpoints.h"

#include "uint256.h"
#include "test_rpicoin.h"

#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_FIXTURE_TEST_SUITE(Checkpoints_tests, BasicTestingSetup)

BOOST_AUTO_TEST_CASE(sanity) {
        uint256 p50000 = uint256("e13891ed03b98324162082f47ae4dd4250a075ae9a96f982961e284aa83259b5"); // Block 50.000
        uint256 p100000 = uint256("c26704a2af85d7da0c4e15a7a6e7648f87e4dd15512fb4586d04fc5ec0b01211"); // Block 100.000
        uint256 p150000 = uint256("69c550f21163c0f0c4bbb07184c7d178f0d372048a8bd1e52473517c33b87b3f"); // Block 150.000
        BOOST_CHECK(Checkpoints::CheckBlock(50000, p50000));
        BOOST_CHECK(Checkpoints::CheckBlock(100000, p100000));
        BOOST_CHECK(Checkpoints::CheckBlock(150000, p150000));


        // Wrong hashes at checkpoints should fail:
        BOOST_CHECK(!Checkpoints::CheckBlock(150000, p50000));
        BOOST_CHECK(!Checkpoints::CheckBlock(50000, p150000));

        // ... but any hash not at a checkpoint should succeed:
        BOOST_CHECK(Checkpoints::CheckBlock(50000 + 1, p150000));
        BOOST_CHECK(Checkpoints::CheckBlock(150000 + 1, p50000));

        BOOST_CHECK(Checkpoints::GetTotalBlocksEstimate() >= 150000);
}

BOOST_AUTO_TEST_SUITE_END()
