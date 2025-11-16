

### cmake for tests

# <<<<<<< HEAD
# set(SOURCE_FILES
#     "base_test.cc"
#     "linked_list_test.cc"
# )
#
# add_executable(all_tests ${SOURCE_FILES})
# target_include_directories(all_tests PRIVATE
#     ${PROJECT_SOURCE_DIR}/include
# )
#
#
# target_link_libraries(all_tests PRIVATE
#     linked_list
#     GTest::gtest_main
# )
#
# include(GoogleTest)
# gtest_discover_tests(all_tests)
# =======
# ### base suite
# set(BASE_SUITE_SOURCES
#     #"base_test.cc"
#     #"linked_list_test.cc"
#     "unity_base_test.c"
# )
# add_executable(base_suite ${BASE_SUITE_SOURCES})
# target_include_directories(base_suite PRIVATE
#     ${PROJECT_SOURCE_DIR}/include
# )
# target_link_libraries(base_suite PRIVATE
#     unity
# )
# add_test(base base_suite)
#
# ### linked list suite
# set(LINKED_LIST_SUITE_SOURCES
#     "linked_list/linked_list_test.c"
# )
# add_executable(linked_list_suite ${LINKED_LIST_SUITE_SOURCES})
# target_include_directories(linked_list_suite PRIVATE
#     ${PROJECT_SOURCE_DIR}/include
# )
# target_link_libraries(linked_list_suite PRIVATE
#     linked_list
#     unity
# )
# add_test(linked_list linked_list_suite)
# >>>>>>> main

