
#include <gtest/gtest.h>
#include <stdlib.h>

#include "linked_list.h"

// Test creating a linked list
TEST(LinkedList, Creation) {

    linked_list * p_list = new_linked_list();
    // reading from an empty list fails
    if (!p_list) {
        FAIL();
    }
}

TEST(LinkedList, Appending) {
    linked_list * p_list = new_linked_list();
    int expected = 42;
    linked_list_append(p_list, expected);
    int actual = linked_list_read(p_list, 0);
    ASSERT_EQ(actual, expected);

}

