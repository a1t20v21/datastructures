#ifndef _BINARY_TREE_
#define _BINARY_TREE_

typedef struct node_{
    char data[10];
    struct node_ *parent;
    struct node_ *left;
    struct node_ *right;
} tree_node;

typedef struct tree_ {
    tree_node *root;
    int size;
} binary_tree;

binary_tree 
* init_tree();

int 
insert_tree_node(binary_tree *tree, char *parent_node_data, char *data, char *orientation);

int 
delete_tree_node(binary_tree *tree, void *data);

int 
preorder_traversal(binary_tree *tree);

int
inorder_traversal(binary_tree *tree);

tree_node 
* get_next_inorder_successer(tree_node *node);

tree_node 
* get_left_most_node(tree_node *node);

tree_node 
* search_node(binary_tree *tree, char *data);

int
destroy_tree(binary_tree *tree);

#endif
