if(PROJECTVARNAME_TESTING_IS_ENABLED)
	################
	# CMocka Tests #
	################
	add_executable(MYPROJECT_tests)
	target_include_directories(MYPROJECT_tests PRIVATE .)
	target_link_libraries(MYPROJECT_tests PRIVATE cmocka_dep)
	target_sources(MYPROJECT_tests PRIVATE
		main.c
		test_suite.c
	)
	target_linker_map(MYPROJECT_tests)

	list(APPEND desired_MYPROJECT_test_flags
		"-Wno-unused-parameter"
	)
	apply_supported_compiler_flags(C MYPROJECT_tests PRIVATE desired_MYPROJECT_test_flags)

	# This registers the test and defines testing targets
	register_cmocka_test(MYPROJECT.Test MYPROJECT_tests)

	################
	# Catch2 Tests #
	################
	add_executable(MYPROJECT_catch_tests)
	target_link_libraries(MYPROJECT_catch_tests PRIVATE catch2_dep)
	target_sources(MYPROJECT_catch_tests PRIVATE
		catch2_test_case.cpp
	)
	register_catch2_test(MYPROJECT.Catch2.Test MYPROJECT_catch_tests)

    ################
    # Google Test #
    ################
    add_executable(MYPROJECT_google_tests)
    target_link_libraries(MYPROJECT_google_tests PRIVATE googletest_dep)
    target_sources(MYPROJECT_google_tests PRIVATE
        google_test_case.cpp
        gmock_test_case.cpp
    )
    register_google_test(MYPROJECT.Google.Test MYPROJECT_google_tests)

endif(PROJECTVARNAME_TESTING_IS_ENABLED)
