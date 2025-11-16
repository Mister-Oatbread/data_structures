

/**
 * Main file for doodling
 */

#include <stdio.h>

#include "linked_list.h"

int main() {
    linked_list * list1 = new_linked_list();
    append(list1, 15);
    append(list1, 16);
    append(list1, 23);
    append(list1, 98);
    append(list1, 4354353);
    for (int i=0; i<20; i++) {
        append(list1, 6);
    }
    insert(list1, 5, 11);

    visualize(list1);

    delete_linked_list(list1);
    printf("delete didn't crash...\n");

    return 0;
}

