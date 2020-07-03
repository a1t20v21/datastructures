/*Header file for DLL*/

#ifndef _DLL_H
#define _DLL_H
typedef struct dll_node_{
    void *data;
    struct dll_node_ *left;
    struct dll_node_ *right;
} dll_node_t;

typedef struct dll_{
    dll_node_t *head;
    int (*key_match)(void *,void *);
    int (*comparison_fn)(void *, void *);
} dll_t;

void register_key_match_callback(dll_t *dll, int (*key_match)(void *, void*));
void register_comparison_callback(dll_t *dll, int (*comparison_fn)(void *, void*));
void * search_dll_by_key(dll_t *dll, void *key);
dll_t * get_new_dll();
int dll_priority_insert_data(dll_t *dll, void *data);
int add_data_to_dll(dll_t *dll, void *app_data);

#define ITERATE_LIST_BEGIN(list_ptr, node_ptr)                              \
{                                                                           \
    dll_node_t *_node_ptr = NULL;                                           \
    node_ptr = list_ptr->head;                                              \
    for(; node_ptr!= NULL; node_ptr = _node_ptr){                           \
        if(!node_ptr) break;                                                \
        _node_ptr = node_ptr->right;

#define ITERATE_LIST_END  }}
#endif