

#ifndef LINKED_LIST
#define LINKED_LIST
    #include <stdbool.h>

    // structs
    struct linked_list;
    struct linked_list_node;

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

    typedef struct linked_list linked_list;
    typedef struct linked_list_node linked_list_node;

    // functions
    linked_list * new_linked_list(void);
    linked_list_node * get_next_entry(linked_list_node * p_current_node, bool * is_final_node);
    int get_node_entry(linked_list_node * p_current_node);
    void set_node_entry(linked_list_node * p_current_node, int content);
#endif // LINKED_LIST


