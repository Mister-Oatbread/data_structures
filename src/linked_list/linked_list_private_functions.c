

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "linked_list_private.h"

/**
 * This function fetches the next node of the linked list
 * the flag p_is_final_node can also be passed to monitor if we are a the final node.
 * if the final node has been reached, then the original node will be returned.
 */
linked_list_node * get_next_node(const linked_list_node * const p_current_node) {
    if (!p_current_node->is_final_node) {
        return p_current_node->p_next_node;
    } else {
        fprintf(stderr, "Next node requested, but node is already terminal. Please make sure you check if a node is terminal before requesting the next one\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * This function returns the entry of the current node
 */
int get_node_content(const linked_list_node * const p_current_node) {
    if (p_current_node->content_is_defined) {
        return p_current_node->node_content;
    } else {
        fprintf(stderr, "Node without content. Please make sure that every node is initializedz\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * This function lets you define the content of a node
 */
void set_node_content(linked_list_node * const p_current_node, const int content) {
    p_current_node->content_is_defined = true;
    p_current_node->node_content = content;
}


