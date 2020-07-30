#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_tree.h"

int main()
{
    binary_tree *tree = init_tree();
    insert_tree_node(tree, NULL, "A", NULL);
    insert_tree_node(tree, "A", "B", "L");
    insert_tree_node(tree, "B", "D", "L");
    insert_tree_node(tree, "A", "C", "R");
    insert_tree_node(tree, "C", "E", "L");
    insert_tree_node(tree, "E", "G", "R");
    insert_tree_node(tree, "C", "F", "R");
    insert_tree_node(tree, "F", "H", "L");
    insert_tree_node(tree, "F", "I", "R");
	printf("\nPreorder Traverse: ");
    preorder_traversal(tree);
	printf("Inorder Traverse: ");
	inorder_traversal(tree);
    free(tree);
    
	binary_tree *tree1 = init_tree();
    insert_tree_node(tree1, NULL, "P", NULL);
    insert_tree_node(tree1, "P", "F", "L");
    insert_tree_node(tree1, "F", "B", "L");
    insert_tree_node(tree1, "F", "H", "R");
    insert_tree_node(tree1, "H", "G", "L");
    insert_tree_node(tree1, "P", "S", "R");
    insert_tree_node(tree1, "S", "R", "L");
    insert_tree_node(tree1, "S", "Y", "R");
    insert_tree_node(tree1, "Y", "T", "L");
    insert_tree_node(tree1, "T", "W", "R");
    insert_tree_node(tree1, "Y", "Z", "R");
	printf("\n\nPreorder Traverse: ");
    preorder_traversal(tree1);
	printf("Inorder Traverse: ");
	inorder_traversal(tree1);
    free(tree1);

    binary_tree *tree2 = init_tree();
    insert_tree_node(tree2, NULL, "A", NULL);
    insert_tree_node(tree2, "A", "B", "L");
    insert_tree_node(tree2, "B", "D", "L");
    insert_tree_node(tree2, "D", "G", "L");
    insert_tree_node(tree2, "G", "K", "L");
    insert_tree_node(tree2, "D", "H", "R");
    insert_tree_node(tree2, "H", "L", "L");
    insert_tree_node(tree2, "H", "M", "R");
    insert_tree_node(tree2, "A", "C", "R");
    insert_tree_node(tree2, "C", "E", "L");
	printf("\n\nPreorder Traverse: ");
    preorder_traversal(tree2);
	printf("Inorder Traverse: ");
	inorder_traversal(tree2);
    free(tree2);
    
	binary_tree *tree3 = init_tree();
    insert_tree_node(tree3, NULL, "A", NULL);
    insert_tree_node(tree3, "A", "B", "L");
    insert_tree_node(tree3, "B", "C", "L");
    insert_tree_node(tree3, "C", "O", "R");
    insert_tree_node(tree3, "B", "D", "R");
    insert_tree_node(tree3, "D", "E", "L");
    insert_tree_node(tree3, "E", "P", "L");
    insert_tree_node(tree3, "P", "R", "L");
    insert_tree_node(tree3, "P", "S", "R");
    insert_tree_node(tree3, "E", "Q", "R");
    insert_tree_node(tree3, "Q", "T", "L");
    insert_tree_node(tree3, "D", "F", "R");
    insert_tree_node(tree3, "F", "G", "R");
    insert_tree_node(tree3, "G", "H", "R");
    insert_tree_node(tree3, "A", "I", "R");
    insert_tree_node(tree3, "I", "J", "L");
    insert_tree_node(tree3, "I", "K", "R");
    insert_tree_node(tree3, "K", "L", "L");
    insert_tree_node(tree3, "L", "M", "L");

	printf("\nPreorder Traverse: ");
    preorder_traversal(tree3);
	printf("Inorder Traverse: ");
	inorder_traversal(tree3);
    free(tree3);


    return 0;
}


