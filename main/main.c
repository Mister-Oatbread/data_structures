

/**
 * Main file for doodling
 */

#include <stdio.h>

#include "linked_list.h"

int main() {
    linked_list * list1 = new_linked_list();
    append(list1, 15);
    append(list1, 20);
    append(list1,  8);
    append(list1, 12);
    append(list1,  4);
    insert(list1,  3, 14);
    insert(list1,  7, 69);
    printf("first element: %d\n", read(list1, 0));

    visualize(list1);

    delete_linked_list(list1);
    printf("delete didn't crash...\n");

    return 0;
}

