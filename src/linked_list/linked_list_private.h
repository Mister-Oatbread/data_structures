

/**
 * Private header file defining helper functions and internal logic
 */

#ifndef LINKED_LIST_PRIVATE
#define LINKED_LIST_PRIVATE

    #include "linked_list.h"

    struct linked_list_node;
    typedef struct linked_list_node linked_list_node;

    /**
     * Linked List head that serves as an entry point
     */
    struct linked_list {
        linked_list_node * p_first_node;
        int number_of_nodes;
    };

    /**
     * Linked list node containing data and next element
     */
    struct linked_list_node {
        int node_content;
        bool content_is_defined;
        linked_list_node * p_next_node;
        bool is_final_node;
    };

    // private functions
    linked_list_node * get_next_node(const linked_list_node * const p_current_node);
    int get_node_content(const linked_list_node * const p_current_node);
    void set_node_content(linked_list_node * const p_current_node, const int content);
#endif // LINKED_LIST_PRIVATE


