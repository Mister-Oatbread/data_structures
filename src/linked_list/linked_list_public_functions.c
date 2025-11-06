

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "linked_list_private.h"

/**
 * This function creates a new linked list with default pararameters
 */
linked_list * new_linked_list() {
    linked_list * p_new_linked_list = malloc(sizeof(linked_list));
    p_new_linked_list->p_first_node = NULL;
    p_new_linked_list->number_of_nodes = 0;
    return p_new_linked_list;
}

/**
 * This function allows to append a node to the end of a linked list
 */
void append(linked_list * const p_linked_list, const int content) {
    // set up the new node
    linked_list_node * p_new_node = malloc(sizeof(linked_list_node));
    p_new_node->node_content = content;
    p_new_node->content_is_defined = true;
    p_new_node->p_next_node = NULL;
    p_new_node->is_final_node = true;

    // check if list is empty, if not go to end of list
    // in either case, append the new node to the end point of the linked list
    linked_list_node * p_current_node;
    if (p_linked_list->p_first_node != NULL) {
        // iterate until you find null
        p_current_node = p_linked_list->p_first_node;
        while (p_current_node->p_next_node != NULL) {
            p_current_node = p_current_node->p_next_node;
        }
        p_current_node->is_final_node = false;
        p_current_node->p_next_node = p_new_node;
    } else {
        // define the new node as the first entry to the linked list
        p_linked_list->p_first_node = p_new_node;
    }
    p_linked_list->number_of_nodes++;
}

/**
 * This function returns the contents at a specific index
 */
int read_content_at(const linked_list * const p_linked_list, const int index) {
    if (index <= p_linked_list->number_of_nodes) {
        linked_list_node * p_current_node;
        p_current_node = p_linked_list->p_first_node;
        for (int i=0; i<index; i++) {
            p_current_node = get_next_node(p_current_node);
        }
        return p_current_node->node_content;
    } else {
        fprintf(stderr, "The requested linked list index is out of bounds.");
        exit(EXIT_FAILURE);
    }
}


