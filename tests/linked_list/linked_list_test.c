
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
void test_list_creation(void) {

    linked_list * p_list = new_linked_list();
    // returned pointer is not NULL
    TEST_ASSERT_TRUE(p_list != nullptr);
}

void test_list_appending(void) {

    linked_list * p_list = new_linked_list();
    int expected = 42;

    append(p_list, expected);
    int actual = read(p_list, 0);
    TEST_ASSERT_EQUAL_INT(actual, expected);
}

void test_list_appending_multiple(void) {

    linked_list * p_list = new_linked_list();
    int expected[] = {2, 1, 3, 4, 7, 11, 18};
    int expected_len = 7;

    for (int i = 0; i< expected_len; i++) {
        append(p_list, expected[i]);
    }

    for (int i = 0; i < expected_len; i++) {
        int actual = read(p_list, i);
        TEST_ASSERT_EQUAL_INT(actual, expected[i]);
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_list_creation);
    RUN_TEST(test_list_appending);
    RUN_TEST(test_list_appending_multiple);

    return UNITY_END();
}
