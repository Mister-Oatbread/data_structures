

## cmake for stack library

# variables
set(STACK "stack")
set(STACK_SOURCES
    "stack.c"
)
set(STACK_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/stack_private.h"
)
set(STACK_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/../../include"
)

# build library
add_library(${STACK} STATIC
    ${STACK_SOURCES}
    ${STACK_HEADERS}
)
target_include_directories(${STACK} PUBLIC
    ${STACK_INCLUDES}
)
