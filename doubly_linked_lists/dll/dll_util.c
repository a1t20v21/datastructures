#include "dll.h"
#include <stdlib.h>
#include <stdio.h>

int remove_data_from_dll_by_data_ptr(dll_t *dll, void *data){

    if(!is_dll_empty(dll)){
        dll_node_t *head = dll->head;
        while(head){
            if(head->data == data){
                printf("%p\n", head->data);
                printf("%p\n", data);
                
                if(head->left == NULL){
                    head->right->left = NULL;
                    head->right = NULL;
                }
                else{
                    head->left->right = head->right;
                    head->right->left = head->left;
                }
                break;
            }
            head = head->left;
        }
    }   
    return 0;
}

int is_dll_empty(dll_t *dll){
    if(!dll || !dll->head) return -1;
    else return 0;
}

void drain_dll(dll_t *dll){
    if(!is_dll_empty(dll)){
        dll_node_t *head = dll->head;
        int i = 1;
        while(head){
            printf("%d\n", i);
            if(head->left != NULL){
                printf("Head Address: %p\n", head);
                head->left->right = NULL;
            }
            else {
                printf("Hello");
                printf("%p\n", head);
            //     dll_node_t *new_node = (dll_node_t*)calloc(1, sizeof(dll_node_t));
            //     dll->head = new_node;
            //     break;
            }
            head = head->left;
            i++;
        }
    }
}