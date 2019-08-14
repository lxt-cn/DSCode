#include "BinaryTree.h"

void BinaryTreeTest()
{
	char array[] = { 'A','B','D','#','#','#','C','E','#','#','F','#','#' };
	int i = 0;
	BTNode* tree = BinaryTreeCreate(array, sizeof(array)/sizeof(array[0]), &i);
	
	printf("Size:%d\n", BinaryTreeSize(tree));
	printf("Leaf Size:%d\n", BinaryTreeLeafSize(tree));
	printf("Level 2 Size:%d\n", BinaryTreeLevelKSize(tree, 2));
	BinaryTreePrevOrder(tree);
	printf("\n");
	BinaryTreeInOrder(tree);
	printf("\n");
	BinaryTreePostOrder(tree);
	printf("\n");
}

int main()
{
	BinaryTreeTest();
	return 0;
}