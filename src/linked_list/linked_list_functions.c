

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * This function creates a new linked list with default pararameters
 */
linked_list * new_linked_list() {
    linked_list * new_linked_list = malloc(sizeof(linked_list));
    new_linked_list->p_first_node = NULL;
    new_linked_list->number_of_nodes = 0;
    return new_linked_list;
}

/**
 * This function allows to append a new entry to a linked list
 */
linked_list_node * add_entry() {

}

/**
 * This function fetches the next node of the linked list
 * the flag p_is_final_node can also be passed to monitor if we are a the final node.
 * if the final node has been reached, then the original node will be returned.
 */
linked_list_node * get_next_entry(linked_list_node * p_current_node, bool * p_is_final_node) {
    if (!p_current_node->is_final_node) {
        *p_is_final_node = false;
        return p_current_node->p_next_node;
    } else {
        *p_is_final_node = true;
        return p_current_node;
    }
}

/**
 * This function returns the entry of the current node
 */
int get_node_entry(linked_list_node * p_current_node) {
    if (p_current_node->content_is_defined) {
        return p_current_node->node_content;
    } else {
        return 0;
    }
}

/**
 * This function lets you define the content of a node
 */
void set_node_entry(linked_list_node * p_current_node, int content) {
    p_current_node->content_is_defined = true;
    p_current_node->node_content = content;
}


