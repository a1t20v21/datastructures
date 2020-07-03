#include "dll.h"
#include <stdlib.h>

dll_t * get_new_dll() {
    dll_t *dll = (dll_t*) calloc(1, sizeof(dll_t));
    dll->head = NULL;
    return dll;
}

void register_key_match_callback(dll_t *dll, int (*key_match)(void *, void*)){
    dll->key_match = key_match;
}

void register_comparison_callback(dll_t *dll, int (*comparison_fn)(void *, void *)){
    dll->comparison_fn = comparison_fn;
}

void * search_dll_by_key(dll_t *dll, void *key) {
    if(!dll || !dll->head) return NULL;

    dll_node_t *head = dll->head;
    while(head){
        if(dll->key_match(head->data, key) == 0){
            return (void*)head->data;
        }
        head = head->right;
    }
    return NULL;
}

int dll_priority_insert_data(dll_t *dll, void *data){
    if(!dll) {
        return -1;
    }

    /*Empty DLL*/
    if(!dll->head){
        add_data_to_dll(dll, data);
        return 0;
    }

    dll_node_t *new_data = (dll_node_t*)calloc(1,sizeof(dll_node_t));
    new_data->data = data;
    new_data->left = NULL;
    new_data->right = NULL;

    /*Only one node in the DLL*/
    if(dll->head && !dll->head->right){
        if(dll->comparison_fn(dll->head->data, data) == -1){
            dll->head->right = new_data;
            new_data->left = dll->head;
        }
        else {
            dll->head->left = new_data;
            new_data->right = dll->head;
            dll->head = new_data;
        }
        return 0;
    }

    /*More than one node*/
    if(dll->comparison_fn(data, dll->head->data) == -1){
        new_data->right = dll->head;
        dll->head->left = new_data;
        dll->head = new_data;
        return 0;
    }

    dll_node_t *prev = NULL;
    dll_node_t *curr = NULL;

    curr = dll->head;
    
    while(curr){
        if(dll->comparison_fn(data, curr->data) != -1){
            prev = curr;
            curr = curr->right;
            continue;
        }

        prev->right = new_data;
        new_data->left = prev;
        new_data->right = curr;
        curr->left = new_data;
        return 0;
    }

    prev->right = new_data;
    new_data->left = prev;

    return 0;
}

int add_data_to_dll(dll_t *dll, void *app_data) {
    if(!dll || !app_data) return -1;

    dll_node_t *dll_new_node = (dll_node_t*) calloc(1, sizeof(dll_node_t));
    dll_new_node->left = NULL;
    dll_new_node->right = NULL;
    dll_new_node->data = app_data;

    if(!dll->head){
        dll->head = dll_new_node;
        return 0;
    }

    dll_node_t *first_node = dll->head;
    dll_new_node->right = first_node;
    first_node->left = dll_new_node;
    dll->head = dll_new_node; 
    return 0;
}