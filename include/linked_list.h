

#ifdef __cplusplus
extern "C" {
#endif
/**
 * Public header file defining api for linked list
 */

#ifndef LINKED_LIST
#define LINKED_LIST

    #include <stdbool.h>

    struct linked_list;
    typedef struct linked_list linked_list;

    // public functions
    linked_list * new_linked_list(void);
    void linked_list_append(linked_list * const p_linked_list, const int content);
    int linked_list_read(const linked_list * const p_linked_list, const int index);

#endif // LINKED_LIST


#ifdef __cplusplus
}
#endif
