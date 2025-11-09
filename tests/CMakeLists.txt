

### cmake for tests

### base suite
set(BASE_SUITE_SOURCES
    #"base_test.cc"
    #"linked_list_test.cc"
    "unity_base_test.c"
)
add_executable(base_suite ${BASE_SUITE_SOURCES})
target_include_directories(base_suite PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(base_suite PRIVATE
    unity
)
add_test(base base_suite)

### linked list suite
set(LINKED_LIST_SUITE_SOURCES
    "linked_list/linked_list_test.c"
)
add_executable(linked_list_suite ${LINKED_LIST_SUITE_SOURCES})
target_include_directories(linked_list_suite PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
target_link_libraries(linked_list_suite PRIVATE
    linked_list
    unity
)
add_test(linked_list linked_list_suite)

