

## cmake for linked list library

# variables
set(LINKED_LIST "linked_list")
set(LINKED_LIST_SOURCES
    "linked_list_private_functions.c"
    "linked_list_public_functions.c"
)
set(LINKED_LIST_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/../../include/linked_list.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/linked_list_private.h"
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


