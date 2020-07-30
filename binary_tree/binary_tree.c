#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_tree.h"

binary_tree * init_tree()
{
    binary_tree *tree = calloc(1, sizeof(binary_tree));
    if(tree) {
        tree->root = NULL;
        tree->size = 0;
        return tree;
    }
    return NULL;
}

tree_node * search_node(binary_tree *tree, char *data)
{
    if(!tree || !tree->root || !data) return NULL;
    /*only one node*/
    if(strcmp(tree->root->data, data) == 0)
    {
        return tree->root;
    }

    tree_node *node = tree->root;
    
    while(node)
    {
        
        if(strcmp(node->data, data) == 0)
        {
            return node;
        }
        else
        { 
            if(node->left)
            {
                node = node->left;
            }
            else
            {
                if(node->right)
                {
                    node = node->right;
                }
                else
                {
                    if(node->parent == tree->root)
                    {
                        if(tree->root->right)
                        {
                            node = tree->root->right;
                        }
                    }
                    else
                    {
                        while(node != tree->root)
                        {
                            if(node->parent->right)
                            {
                                if(node->parent->right == node)
                                    node = node->parent;
                                else
                                {
                                    node = node->parent->right;
                                    break;
                                }
                            }
                            else
                                node = node->parent; 
                        }
                    }
                }
            }
        }
    }
    
    return NULL;
}

int inorder_traversal(binary_tree *tree)
{
	if(!tree || !tree->root) return -1;

	char inorder_list[100][10];
	int j = 0;

	if(tree->root->left)
	{
		tree_node *left_most = get_left_most_node(tree->root);
		strcpy(inorder_list[j++], left_most->data);
		int i = 0;
		tree_node *next_inorder_succ = get_next_inorder_successer(left_most);
		while(next_inorder_succ)
		{	
			strcpy(inorder_list[j++], next_inorder_succ->data);
			next_inorder_succ = get_next_inorder_successer(next_inorder_succ);
		}
	}

	for(int k = 0; k < j; k++)
	{
		printf("%s ", inorder_list[k]);
	}
	printf("\n");

	return 0;
}

tree_node * get_left_most_node(tree_node *node)
{
	if(!node || !node->left) return NULL;
	
	while(node->left)
	{
		node = node->left;
	}
	return node;
}

tree_node * get_next_inorder_successer(tree_node *node)
{
	
	if(!node) return NULL;
	/*given node is the root node*/
	if(!node->parent)
		if(node->right->left)
			return get_left_most_node(node->right);
		else
			return node->right;

	/*node is a left child of its parent*/
	if(node == node->parent->left)
	{
		if(!node->right)
			return node->parent;
		else
		{
			if(node->right->left)
				return get_left_most_node(node->right);
			else 
				return node->right;
		}
	}

	/*node is a right child of its parent*/
	if(node == node->parent->right)
	{
		if(node->right)
		{
			if(node->right->left)
				return get_left_most_node(node->right);
			else
				return node->right;
		}
	}
	
	tree_node *gp = node->parent->parent;
	tree_node *parent = node->parent;
	
	while(gp && gp->left != parent)
	{
		parent = gp;
		gp = gp->parent;
	}
	
	return	gp;
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
        tree->size++;
        return 0;
    }

    tree_node *parent_node = search_node(tree, parent_node_data);
    if(parent_node)
    {
        tree_node *temp;
        if(strcmp(orientation, "L") == 0)
        {
            if(parent_node->left)
            {
                temp = parent_node->left;
                parent_node->left = node;
                node->left = temp;
                node->parent = parent_node;
                tree->size++;
            }
            else
            {
                parent_node->left = node;
                node->parent = parent_node;
                tree->size++;
            }
        }
        else
        {
            if(parent_node->right)
            {
                temp = parent_node->right;
                parent_node->right = node;
                node->right = temp;
                node->parent = parent_node;
                tree->size++;
            }
            else
            {
                parent_node->right = node;
                node->parent = parent_node;
                tree->size++;
            }
            return 0;
        }
    }
    return -1;
}

int delete_tree_node(binary_tree *tree, void *data)
{
    //
}

int preorder_traversal(binary_tree *tree)
{
    char preorder_list[100][10];
    int i = 0, right_subtree = 0;

    if(!tree || !tree->root) return -1;
    
    tree_node *root = tree->root;
    tree_node *current = root;
    
    /*only one node
    if(tree->root && tree->root->parent == NULL) {
        if(tree->root->data == data)
            return tree->root;
        else
            return NULL;
    }*/

    tree_node *node = tree->root;
    
    while(node)
    {   
        if(i >= tree->size) break;
        strcpy(preorder_list[i++], node->data);    
        if(node->left)
        {
            node = node->left;
        }
        else
        {
            if(node->right)
            {
                node = node->right;
            }
            else
            {
                
                if(right_subtree == 0)
                {
                    if(node->parent == tree->root)
                    {
                        if(tree->root->right)
                        {
                            right_subtree = 1;
                            node = tree->root->right;
                        }
                        else
                        {
                            break;
                        }                    
                    }
                    else
                    {
                        while(node->parent != tree->root)
                        {
                            if(node->parent->right)
                            {
                                if(node->parent->right == node)
                                    node = node->parent;
                                else
                                {
                                    node = node->parent->right;
                                    break;
                                }
                            }
                            else
                                node = node->parent; 
                        }
                        if(node->parent == tree->root)
                        {
                            if(node->parent->right)
                            {
                                node = node->parent->right;
                            }
                        }
                    }
                }
                else
                {
                    if(node->parent->right)
                    {
                        if(node->parent->right == node)
                            node = node->parent;
                        else
                            node = node->parent->right;
                    }
                    else
                    {
                        node = node->parent;
                    } 
                }
            }
        }
    }

    for(int j = 0; j < i; j++)
    {
        printf("%s ", preorder_list[j]);
    }
    printf("\n");
    
    return 0;
}

