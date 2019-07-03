// Copyright (c) 2018 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WISPR_ACCUMULATORCHECKPOINTS_JSON_H
#define WISPR_ACCUMULATORCHECKPOINTS_JSON_H

#include <string>
std::string GetMainCheckpoints() {
    std::string strMainCheckpoints = "[\n"
                                     "  {\n"
                                     "    \"height\": 400002,\n"
                                     "    \"1\": \"0\",\n"
                                     "    \"5\": \"0\",\n"
                                     "    \"10\": \"0\",\n"
                                     "    \"50\": \"0\",\n"
                                     "    \"100\": \"909c6636106f3c1a9e3271dd8b97f6124eb1934e65573545888c625b749ece88f13c976697225364a33070df0a1d63422bc14036584f62f3ef6f9d19b9c715b8bb41af49a61500d87044c5f5927f54592d080fe7882227128ccd037c86764f25d9a08a50bf89b6a13fdd0a869e85a223a00c39341adbbfc7ca132bbefd4c4a77\",\n"
                                     "    \"500\": \"0\",\n"
                                     "    \"1000\": \"0\",\n"
                                     "    \"5000\": \"0\"\n"
                                     "  },\n"
                                     "  {\n"
                                     "    \"height\": 400475,\n"
                                     "    \"1\": \"c3cf46df7238e76355f1b9394d8375a7e633c39a048c69264381e3a7e4c7b51b10f51ed39912d4be029903b4ab379a5488b15567429b2b9f974c6b4f94e3806869cb90682c5311c82c6e6c5d629906c781dfce194e78c8951da202162aca6db2b095d02d297202e1e533bf740e92a328a826fe03b195cc6cc0f453b7b4f53ead\",\n"
                                     "    \"5\": \"509f41d6afc1202e025ef4f50ee7ca24391c83d40327d5f623419b65b3c5b4322ee3417ccbac00a3c892e9783ccc9cacc77eef59748a118e25d5d888be7a22dcff1a61eb68f723b4ac70e202581ecf06a4882f933b57d4186902916d06fb85b3f163a3d43743ac3b66197cb3529d16efc60e556f8dc9be4f66d7f96efad187f5\",\n"
                                     "    \"10\": \"d9d3b8f6da18ac3c4a6890266514e470cca5365fcceff33205b347e7ac6077ebc99e116e3028a2f98751ff6f9fb2f12d8ecfa38e8fb8b6f0278427a776780405504d69803491393a2decee5594a21da3977df4935f3a32bc1f8f46c6cd0634687f7389888e22397650d3b8a41e512ad2a3fd9bbdae6a66fab3b7788f4bee537b\",\n"
                                     "    \"50\": \"511c51c82100b7e479fde153801fe4e6319e81bbee69e9ba638877498e9a377aba28debf034daf9b36ff5c34ffa3ead40ae627714d1802ce6ac896cc48a6072539f2d1b900d78a0b50abda8c1bf97c7441a5becbc5dea9e05900a5dcc1cf94e87b829ffa832bbe51fd7b8b403ae6724dc4fedf30d74ba7e8546f18c1af19f2f5\",\n"
                                     "    \"100\": \"1df68d5ef915b5cc61eefbc27afa855f89f78d346373700b0a7c65b1d9c95a9e86b98c9066240435f3ae7e6584ed377ff23c8c171f5d94cb539cec87e475c2cc5edd1319241e4417cbd63e88aea3c43b61f1f78fd93b45253a896f3a31ef563fc263f223418eae4c9991bcdf1dceda153ee989ed2112ead6a171c6775db3aedd\",\n"
                                     "    \"500\": \"b11c1ead0ca762e90fbe49f5229f9bdf7f56ebb1081a7af2017b502190ce5c07ffc84137047ccb24994bb32ac6ba0ad12d4ef8cf8872317b0ad8c87c10f6c1063163b6ea33ef1b719f4fd736d5e02ede89aa48d6c301855a42a946ec012eb17b84e80bae9f91bc712425d13545e2975b47e616ea34fb93c42048574a0283fb1b\",\n"
                                     "    \"1000\": \"ce2af48b6e270499e69aed438af1bba0874acfe381d4fab2e67d030f4e3ccdb232520c249bb8065a5b716de60ebeaa7134968bd131e1ec3460a253f5057cd47b753fe7b2118697e9968b07107bd151dc20a8f6a3278416514aab9bcdcb2642a5ebd26cfbe28d545ed2a383efec4d7287e53d18ae2ea56dac5b62cf6e54035dc3\",\n"
                                     "    \"5000\": \"1a38ac28dce1d2e52d81bef524cd5bb80754a40704ae3b157763d9d4b304c24d37b85639ffed8fd6eff7d0c53230c0697e9fed4eba8ac7aca20ed199a26b5b4ce1d6d70f1528657b95ce18f217dec87e626d6b626ef03fc0d9128ca51dcf120100b642f98c606fa8749e00ae2fec7fdeaf82b567a513ccc1db8e03f0d5eed21d\"\n"
                                     "  }\n"
                                     "]";
    return strMainCheckpoints;
}

std::string GetTestCheckpoints() {
    std::string strTestCheckpoints = "[\n"
                                     "  {\n"
                                     "    \"height\": 0,\n"
                                     "    \"1\": \"0\",\n"
                                     "    \"5\": \"0\",\n"
                                     "    \"10\": \"0\",\n"
                                     "    \"50\": \"0\",\n"
                                     "    \"100\": \"0\",\n"
                                     "    \"500\": \"0\",\n"
                                     "    \"1000\": \"0\",\n"
                                     "    \"5000\": \"0\"\n"
                                     "  }\n"
                                     "]";
    return strTestCheckpoints;
}

std::string GetRegTestCheckpoints() {
    std::string strRegTestCheckpoints = "[\n"
                                        "  {\n"
                                        "    \"height\": 0,\n"
                                        "    \"1\": \"0\",\n"
                                        "    \"5\": \"0\",\n"
                                        "    \"10\": \"0\",\n"
                                        "    \"50\": \"0\",\n"
                                        "    \"100\": \"0\",\n"
                                        "    \"500\": \"0\",\n"
                                        "    \"1000\": \"0\",\n"
                                        "    \"5000\": \"0\"\n"
                                        "  }\n"
                                        "]";
    return strRegTestCheckpoints;
}

#endif //WISPR_ACCUMULATORCHECKPOINTS_JSON_H