

/**
 * Main file for doodling
 */

#include <stdio.h>

#include "linked_list.h"

int main() {
    linked_list * list1 = new_linked_list();
    linked_list_append(list1, 15);
    printf("first element: %d\n", linked_list_read(list1, 0));

    delete_linked_list(list1);
    printf("delete didn't crash...\n");
    printf("first element: %d\n", read(list1, 0));

    return 0;
}

