
set(UNITY_SOURCES
    "unity.c"
)
set(UNITY_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/../../include/unity.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../include/unity_internals.h"
)
set(UNITY_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/../../include"
)

add_library(unity STATIC
    ${UNITY_SOURCES}
    ${UNITY_HEADERS}
)

target_include_directories(unity PUBLIC
    ${UNITY_INCLUDES}
)
