
#include <stdlib.h>
#include <unity.h>

#include "linked_list.h"

void setUp(void) {
    // empty
}

void tearDown(void) {
    // also empty
}

// Test creating a linked list
void test_list_creation {

    linked_list * p_list = new_linked_list();
    // returned pointer is not NULL
    TEST_ASSERT_TRUE(p_list != nullptr);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_list_creation);

    return UNITY_END();
}
