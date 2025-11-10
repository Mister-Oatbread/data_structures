

/**
 * Private header file defining helper functions and internal logic
 */

#ifndef LINKED_LIST_PRIVATE
#define LINKED_LIST_PRIVATE

    #include "linked_list.h"

    struct linked_list_node;
    typedef struct linked_list_node linked_list_node;

    /**
     * Linked List head that serves as an entry point to the linked list.
     *
     * While the actual content is contained within the linked list nodes, the linked list
     * is publically accessible and can be interacted with outside the library.
     * It should only be initialized using the function "new_linked_list()".
     */
    struct linked_list {
        linked_list_node * p_first_node;
        int number_of_nodes;
        bool alive;
    };

    /**
     * Linked list node containing data and next node.
     *
     * This struct is private and can only be indirectly manipulated using the functions in the public api.
     * Since we want to store values in the linked list, but not manage its nodes externally, this is a good practice.
     * Node content may be assigned or null, but one should acquire information on the
     * state of the content using the boolean "content_is_defined".
     * Same goes for the pointer to the next node, which may also be null, but should be
     * requested via "is_final_node".
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
    bool check_if_alive(const linked_list * const p_linked_list);
#endif // LINKED_LIST_PRIVATE


