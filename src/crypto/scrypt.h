#ifndef SCRYPT_H
#define SCRYPT_H
#include <cstdlib>
#include <cstdint>
#include <string>
#include "uint256.h"

void scrypt(const char *pass, unsigned int pLen, const char *salt, unsigned int sLen, char *output, unsigned int N,
            unsigned int r, unsigned int p, unsigned int dkLen);

uint256 scrypt_salted_multiround_hash(const void *input, size_t inputlen, const void *salt, size_t saltlen,
                                      const unsigned int nRounds);

uint256 scrypt_salted_hash(const void *input, size_t inputlen, const void *salt, size_t saltlen);
uint256 scrypt_hash(const void *input, size_t inputlen);

uint256 scrypt_blockhash(const void *input);

#endif
