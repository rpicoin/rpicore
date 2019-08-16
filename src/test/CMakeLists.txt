# Copyright (c) 2018 The Bitcoin developers

CMAKE_MINIMUM_REQUIRED(VERSION 3.14.5)

project(wispr-test)

# Process json files.
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/data")

find_program(PYTHON python)
function(gen_json_header NAME)
	set(HEADERS "")
	foreach(f ${ARGN})
		set(h "${CMAKE_CURRENT_BINARY_DIR}/${f}.h")

		# Get the proper name for the test variable.
		get_filename_component(TEST_NAME ${f} NAME_WE)
		add_custom_command(OUTPUT ${h}
			COMMAND ${PYTHON}
			ARGS
				"${CMAKE_CURRENT_SOURCE_DIR}/data/generate_header.py"
				"${TEST_NAME}"
				"${CMAKE_CURRENT_SOURCE_DIR}/${f}" > ${h}
			MAIN_DEPENDENCY ${f}
			DEPENDS
				"data/generate_header.py"
			VERBATIM
		)
		list(APPEND HEADERS ${h})
	endforeach(f)
	set(${NAME} "${HEADERS}" PARENT_SCOPE)
endfunction()

gen_json_header(JSON_HEADERS
	data/script_tests.json
	data/base58_keys_valid.json
	data/base58_encode_decode.json
	data/base58_keys_invalid.json
	data/tx_invalid.json
	data/tx_valid.json
	data/sighash.json
)

include(TestSuite)
create_test_suite(wispr)
#add_dependencies(check check-wispr)

add_test_to_suite(wispr test_wispr
		accounting_tests.cpp
		addrman_tests.cpp
		alert_tests.cpp
		allocator_tests.cpp
		arith_uint256_tests.cpp
		base32_tests.cpp
		base58_tests.cpp
		base64_tests.cpp
		benchmark_zerocoin.cpp
		bip32_tests.cpp
		bloom_tests.cpp
		budget_tests.cpp
		checkblock_tests.cpp
		Checkpoints_tests.cpp
		coins_tests.cpp
		compress_tests.cpp
		crypto_tests.cpp
		DoS_tests.cpp
		getarg_tests.cpp
		hash_tests.cpp
		key_tests.cpp
		libzerocoin_tests.cpp
		main_tests.cpp
		mempool_tests.cpp
		miner_tests.cpp
		mruset_tests.cpp
		multisig_tests.cpp
		netbase_tests.cpp
		pmt_tests.cpp
		reverselock_tests.cpp
		rpc_tests.cpp
		rpc_wallet_tests.cpp
		sanity_tests.cpp
		scheduler_tests.cpp
		script_P2SH_tests.cpp
		script_tests.cpp
		scriptnum_tests.cpp
		serialize_tests.cpp
		sighash_tests.cpp
		sigopcount_tests.cpp
		skiplist_tests.cpp
		test_wispr.cpp
		test_zerocoin.cpp
		timedata_tests.cpp
		torcontrol_tests.cpp
		transaction_tests.cpp
		tutorial_zerocoin.cpp
		uint256_tests.cpp
		univalue_tests.cpp
		util_tests.cpp
		zerocoin_bignum_tests.cpp
		zerocoin_chain_tests.cpp
		zerocoin_coinspend_tests.cpp
		zerocoin_denomination_tests.cpp
		zerocoin_implementation_tests.cpp
		zerocoin_transactions_tests.cpp


	# Tests generated from JSON
	${JSON_HEADERS}
)

target_include_directories(test_wispr
	PUBLIC
		# To access the generated json headers.
		${CMAKE_CURRENT_BINARY_DIR}
)

find_package(Boost 1.68 REQUIRED unit_test_framework)

target_link_libraries(test_wispr Boost::unit_test_framework rpcclient server)

# We need to detect if the BOOST_TEST_DYN_LINK flag is required.
set(CMAKE_REQUIRED_LIBRARIES Boost::unit_test_framework)
#check_cxx_source_compiles("
#	#define BOOST_TEST_DYN_LINK
#	#define BOOST_TEST_MAIN
#	#include <boost/test/unit_test.hpp>
#" BOOST_TEST_DYN_LINK)

if(BOOST_TEST_DYN_LINK)
	target_compile_definitions(test_wispr PRIVATE BOOST_TEST_DYN_LINK)
endif(BOOST_TEST_DYN_LINK)

if(BUILD_BITCOIN_WALLET)
	target_sources(test_wispr
		PRIVATE
			../wallet/test/psbt_wallet_tests.cpp
			../wallet/test/wallet_tests.cpp
			../wallet/test/wallet_crypto_tests.cpp
			../wallet/test/coinselector_tests.cpp
			../wallet/test/init_tests.cpp
			../wallet/test/rpc_wallet_tests.cpp
			../wallet/test/hdwallet_tests.cpp
			../wallet/test/rpc_hdwallet_tests.cpp
			../wallet/test/stake_tests.cpp
			../wallet/test/hdwallet_test_fixture.cpp
			../wallet/test/wallet_test_fixture.cpp
			../wallet/test/init_test_fixture.cpp
			../wallet/test/init_test_fixture.h
	)
endif()
