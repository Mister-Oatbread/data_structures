

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
    return p_new_linked_list;
}

/**
 *  This function deletes a given linked list with all of its entries
 */
void delete_linked_list(linked_list * p_linked_list) {
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

    // free linked list
    free(p_linked_list);
    p_linked_list = NULL;
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

/**
 * This function returns the index of the first node that contains the same content as the parameter content.
 * If the content was not found the function throws an error.
*/

int get_content_index(const linked_list * const p_linked_list, const int content){
    check_if_alive(p_linked_list);

    int index = 0;

    if(find(p_linked_list, content, &index)){
        return index;
    }
    else{
        fprintf(stderr, "There is no matching content in the list.");
        exit(EXIT_FAILURE);
    }
}

/**
 * This function checks if a content exists in the list.
*/

bool content_exists(const linked_list * const p_linked_list, const int content){
    check_if_alive(p_linked_list);

    int index = 0;

    return(find(p_linked_list, content, &index));
}
 * This function returns the number of nodes of a given linked list
 */
int get_number_of_nodes(const linked_list * const p_linked_list) {
    return p_linked_list->number_of_nodes;
}

/**
 * This function allows you to insert some content at a specific location
 * in the linked list.
 */
void insert(linked_list * const p_linked_list, const int index, const int content) {
    check_if_alive(p_linked_list);

    // check if out of bounds
    if (p_linked_list->number_of_nodes < index) {
        fprintf(stderr, "The requested linked list index is out of bounds.\n");
        exit(EXIT_FAILURE);
    }

    // go to relevant index
    linked_list_node * p_node_before_index = p_linked_list->p_first_node;
    for (int counter=0; counter<index-1; counter++) {
        p_node_before_index = get_next_node(p_node_before_index);
    }

    // create new node
    linked_list_node * p_new_node = malloc(sizeof(linked_list_node));
    p_new_node->node_content = content;
    p_new_node->content_is_defined = true;
    p_new_node->is_final_node = p_node_before_index->is_final_node;

    // change pointers accordingly
    p_new_node->p_next_node = p_node_before_index->p_next_node;
    p_node_before_index->p_next_node = p_new_node;
    p_node_before_index->is_final_node = false;

    p_linked_list->number_of_nodes++;
}

/**
 * This function prints out every element of a given linked list.
 */
void visualize(const linked_list * const p_linked_list) {
    check_if_alive(p_linked_list);

    // setup for nice formatting
    int max_prints_per_line = 20;
    int current_number_of_prints = 0;

    // print every node content while respecting line breaks
    linked_list_node * p_current_node = p_linked_list->p_first_node;
    do {
        if (p_current_node->content_is_defined) {
            printf("%d", p_current_node->node_content);
            p_current_node = get_next_node(p_current_node);

            if (current_number_of_prints > max_prints_per_line) {
                printf("\n");
                current_number_of_prints = 0;
            } else {
                printf(" - ");
                current_number_of_prints++;
            }
        } else {
            fprintf(stderr, "The content of this node is not defined\n");
            exit(EXIT_FAILURE);
        }
    } while (!p_current_node->is_final_node);

    // print one final time
    printf("%d\n", p_current_node->node_content);

}


