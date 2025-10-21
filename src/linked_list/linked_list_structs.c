

/**
 * This file provides structs that are used for the linked list
 */

#include <stdbool.h>
#include "linked_list.h"

struct linked_list {
    linked_list_node * p_first_node;
};

struct linked_list_node {
    int node_content;
    linked_list_node * p_next_node;
    bool is_final_node;
};

