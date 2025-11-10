

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "linked_list_private.h"

/**
 * This function creates a new linked list with a full set of default pararameters.
 * Note that the function returns a pointer, so this "constructor" should be called accordingly.
 */
linked_list * new_linked_list() {
    linked_list * p_new_linked_list = malloc(sizeof(linked_list));
    p_new_linked_list->p_first_node = NULL;
    p_new_linked_list->number_of_nodes = 0;
    p_new_linked_list->alive = true;
    return p_new_linked_list;
}

/**
 *  This function deletes a given linked list with all of its entries
 */
void delete_linked_list(linked_list * const p_linked_list) {
    check_if_alive(p_linked_list);

    // delete all nodes, but only if list is non empty
    if (p_linked_list->number_of_nodes > 0) {
        // setup
        linked_list_node * p_current_node = p_linked_list->p_first_node;
        linked_list_node * p_next_node;

        // free nodes until you hit the end
        while (!p_current_node->is_final_node) {
            p_next_node = p_current_node->p_next_node;
            free(p_current_node);
            p_current_node = p_next_node;
        }
        // free last node without getting next node
        free(p_current_node);
    }
    p_linked_list->alive = false;

    // free linked list
    free(p_linked_list);
}

/**
 * This function allows to append a node to the end of a linked list.
 * It will find the last node of the linked list and add a pointer there referring to itself.
 * If the list is empty, it will add this node to the linked list struct.
 * The appended node will then be the new end of the linked list, and it will be fully set up accordingly.
 */
void append(linked_list * const p_linked_list, const int content) {
    check_if_alive(p_linked_list);

    // set up the new node
    linked_list_node * p_new_node = malloc(sizeof(linked_list_node));
    p_new_node->node_content = content;
    p_new_node->content_is_defined = true;
    p_new_node->p_next_node = NULL;
    p_new_node->is_final_node = true;

    // check if list is empty, if not go to end of list
    // in either case, append the new node to the end point of the linked list
    linked_list_node * p_current_node;
    if (p_linked_list->p_first_node == NULL) {

        // define the new node as the first entry to the linked list
        p_linked_list->p_first_node = p_new_node;
    } else {

        // iterate until you find null
        p_current_node = p_linked_list->p_first_node;
        while (!(p_current_node->is_final_node)) {
            p_current_node = get_next_node(p_current_node);
        }
        p_current_node->is_final_node = false;
        p_current_node->p_next_node = p_new_node;
    }
    p_linked_list->number_of_nodes++;
}

/**
 * This function returns the contents of a linked list at a specific index.
 * The index may be out of bounds, which will cause an error to be thrown.
 * The index must be a non negative number
 */
int read(const linked_list * const p_linked_list, const int index) {
    check_if_alive(p_linked_list);

    // declare error cases
    int number_of_nodes = p_linked_list->number_of_nodes;
    bool index_outside_bounds = index > (number_of_nodes-1);
    bool index_is_negative = index < 0;

    if (index_outside_bounds) {
        fprintf(stderr, "The requested linked list index is out of bounds.");
        exit(EXIT_FAILURE);
    } else if (index_is_negative) {
        fprintf(stderr, "The index for a linked list must be positive.");
        exit(EXIT_FAILURE);
    } else {
        linked_list_node * p_current_node;
        p_current_node = p_linked_list->p_first_node;
        for (int i=0; i<index; i++) {
            p_current_node = get_next_node(p_current_node);
        }
        return p_current_node->node_content;
    }
}


