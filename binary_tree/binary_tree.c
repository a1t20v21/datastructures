#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_{
    char data[10];
    struct node_ *parent;
    struct node_ *left;
    struct node_ *right;
} tree_node;

typedef struct tree_ {
    tree_node *root;
} binary_tree;

binary_tree * init_tree();
int insert_tree_node(binary_tree *tree, char *parent_node_data, char *data, char *orientation);
int delete_tree_node(binary_tree *tree, void *data);
void inorder_traversal(binary_tree *tree);
tree_node * search_node(binary_tree *tree, char *data);
void save_tree_in_file(char *parent_node, char *child_node, char *orientation);

int main()
{
    binary_tree *tree = init_tree();
    insert_tree_node(tree, NULL, "A", NULL);
    return 0;
}

binary_tree * init_tree()
{
    binary_tree *tree = calloc(1, sizeof(binary_tree));
    if(tree) {
        tree->root = NULL;
        return tree;
    }
    return NULL;
}

tree_node * search_node(binary_tree *tree, char *data)
{
    if(!tree || !tree->root || !data) return NULL;
    
    /*only one node*/
    if(tree->root && tree->root->parent == NULL) {
        if(tree->root->data == data)
            return tree->root;
        else
            return NULL;
    }

    tree_node *node = tree->root;
    tree_node *prev = node;
    
    while(node->left != NULL)
    {
        if(node->data == data)
            return node;
        else
        {
            node = node->left;
        }
    }

    node = node->parent;
    while(node->parent !=NULL )
    {
        if(node->right)
            node = node->right;
            if(node->data == data)
                return node;
            if(node->left)
            {
                while(node->left != NULL)
                {
                    if(node->data == data)
                        return node;
                    else
                    {
                        node = node->left;
                    }
                }
                node = node->parent;
            }
        else
            node = node->parent->parent;
    }
    
    return NULL;
}

int insert_tree_node(binary_tree *tree, char *parent_node_data, char *data, char *orientation)
{
    if(!tree)
    {
        perror("Empty tree! Initialize it first.");
        return -1;
    }
    
    if(!data)
    {
        perror("Empty node value");
        return -1;
    }

    tree_node *node = calloc(1, sizeof(tree_node));
    strcpy(node->data, data);
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    
    /*First node*/
    if(!tree->root) {
        tree->root = node;
        save_tree_in_file(parent_node_data, data, orientation);
        return 0;
    }
    
    tree_node *parent_node = search_node(tree, parent_node_data);
    if(parent_node)
    {
        tree_node *temp;
        if(orientation == "L")
        {
            if(parent_node->left)
            {
                temp = parent_node->left;
                parent_node->left = node;
                node->left = temp;
            }
            else
            {
                parent_node->left = node;
            }
        }
        else
        {
            if(parent_node->right)
            {
                temp = parent_node->right;
                parent_node->right = node;
                node->right = temp;
            }
            else
            {
                parent_node->right = node;
            }
            node->parent = parent_node;
            save_tree_in_file(parent_node_data, data, orientation);
            return 0;
        }
    }
    return -1;
}

int delete_tree_node(binary_tree *tree, void *data)
{
    //
}

void inorder_traversal(binary_tree *tree)
{
    //
}

void save_tree_in_file(char *parent_node, char *child_node, char *orientation)
{
    FILE *fp;
    fp = fopen("binary_tree.txt", "a");
    if(parent_node && orientation)
        fprintf(fp, "%s,%s,%s\n", parent_node, child_node, orientation);
    else
        fprintf(fp, "%s\n", child_node);
    fclose(fp);
}
