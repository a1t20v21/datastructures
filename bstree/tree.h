#ifndef __TREE__
#define __TREE__

typedef struct tree_node_{
    struct tree_node_ *parent;
    struct tree_node_ *left;
    struct tree_node_ *right;
    int data;
} tree_node_t;

typedef struct tree_{
    tree_node_t *root;
} tree_t;

tree_t * init_tree(void);
tree_node_t * init_tree_node(int data);
int add_tree_node_by_value(tree_t *tree, int data);
tree_node_t * get_left_most(tree_node_t *node);
tree_node_t * get_next_inorder_succ(tree_node_t *node);

#define ITERATE_BST_BEGIN(treeptr, currentnodeptr)            \
{                                                             \
    tree_node_t *_next = NULL;                                \
    for(currentnodeptr = get_left_most(treeptr->root); currentnodeptr ; currentnodeptr = _next){    \
                        _next = get_next_inorder_succ(currentnodeptr);

#define ITERATE_BST_END }}

#endif
