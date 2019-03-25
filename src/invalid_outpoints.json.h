// Copyright (c) 2018 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RPICoin_INVALID_OUTPOINTS_JSON_H
#define RPICoin_INVALID_OUTPOINTS_JSON_H
#include <string>

std::string LoadInvalidOutPoints()
{
    std::string str = "[\n"
            "  {\n"
            "    \"txid\": \"0\",\n"
            "    \"n\": 0\n"
            "  }\n"
            "]";
    return str;
}

#endif //RPICoin_INVALID_OUTPOINTS_JSON_H
