

### cmake for final executable

set(LIBRARIES
    "linked_list"
)
set(SOURCE_FILES
    "main.c"
)

if (RUN_TESTS)
    set(SOURCE_NAME "data_structures_test")
else()
    set(SOURCE_NAME "data_structures")
endif()

add_executable(${SOURCE_NAME} ${SOURCE_FILES})

target_link_libraries(${SOURCE_NAME} PUBLIC ${LIBRARIES})


