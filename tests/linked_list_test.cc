
#include <gtest/gtest.h>
#include <stdlib.h>

#include "linked_list.h"

// Test creating a linked list
TEST(LinkedList, Creation) {

    linked_list * p_list = new_linked_list();
    // returned pointer is not NULL
    ASSERT_NE(p_list, nullptr);
}

TEST(LinkedList, Appending) {
    linked_list * p_list = new_linked_list();
    int expected = 42;

    linked_list_append(p_list, expected);
    int actual = linked_list_read(p_list, 0);
    ASSERT_EQ(actual, expected);
}

TEST(LinkedList, AppendingMultiple) {

    linked_list * p_list = new_linked_list();
    int expected[] = {2, 1, 3, 4, 7, 11, 18};
    int expected_len = 7;

    for (int i = 0; i< expected_len; i++) {
        linked_list_append(p_list, expected[i]);
    }

    for (int i = 0; i < expected_len; i++) {
        int actual = linked_list_read(p_list, i);
        EXPECT_EQ(actual, expected[i]);
    }
}

TEST(LinkedList, ReadingOutOfBounds) {

    linked_list * p_list = new_linked_list();

    // reading from empty list fails
    ASSERT_DEATH({
            linked_list_read(p_list, 0);
            }, "The requested linked list index is out of bounds.");

    // reading at negative index fails
    ASSERT_DEATH({
            linked_list_read(p_list, -1);
            }, "The index for a linked list must be positive.");

    // reading at too large index fails
    int number = 42;
    linked_list_append(p_list, number);
    ASSERT_DEATH({
            linked_list_read(p_list, 1);
            }, "The requested linked list index is out of bounds.");
}
