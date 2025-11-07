

### cmake for tests

set(SOURCE_FILES
    "base_test.cc"
    "linked_list_test.cc"
)

add_executable(all_tests ${SOURCE_FILES})
target_include_directories(all_tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)


target_link_libraries(all_tests PRIVATE
    linked_list
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(all_tests)

