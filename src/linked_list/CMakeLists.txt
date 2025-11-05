

## cmake for linked list library

# variables
set(lOOPS "linked_list")
set(LINKED_LIST_SOURCES
    "linked_list_functions.c"
    "linked_list_structs.c"
)
set(LINKED_LIST_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/../../include/linked_list.h"
)
set(LINKED_LIST_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/../../include"
)

# build library
add_library(${LINKED_LIST} STATIC
    ${LINKED_LIST_SOURCES}
    ${LINKED_LIST_HEADERS}
)
target_include_directories(${LINKED_LIST} PUBLIC
    ${LINKED_LIST_INCLUDES}
)


