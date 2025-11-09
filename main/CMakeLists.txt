

### cmake for final executable

set(LIBRARIES
    "linked_list"
)
set(SOURCE_FILES
    "main.c"
)

set(SOURCE_NAME "data_structures")

add_executable(${SOURCE_NAME} ${SOURCE_FILES})

target_link_libraries(${SOURCE_NAME} PUBLIC ${LIBRARIES})


