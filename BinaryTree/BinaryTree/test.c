#include "BinaryTree.h"

void BinaryTreeTest()
{
	char array[] = { 'A','B','D','#','#','#','C','E','#','#','F','#','#' };
	int i = 0;
	BTNode* tree = BinaryTreeCreate(array, sizeof(array)/sizeof(array[0]), &i);
	BTNode* ret = NULL;

	printf("Size:%d\n", BinaryTreeSize(tree));
	printf("Leaf Size:%d\n", BinaryTreeLeafSize(tree));
	printf("Level 2 Size:%d\n", BinaryTreeLevelKSize(tree, 2));
	BinaryTreePrevOrder(tree);
	printf("\n");
	BinaryTreeInOrder(tree);
	printf("\n");
	BinaryTreePostOrder(tree);
	printf("\n");
	BinaryTreeLevelOrder(tree);
	printf("\n");

	ret = BinaryTreeFind(tree, 'E');
	printf("%c\n", ret->_data);

	ret = BinaryTreeFind(tree, 'X');
	printf("%p\n", ret);

	printf("Height:%d\n", BinaryTreeHeight(tree));

	BinaryTreeDestory(&tree);
}

int main()
{
	BinaryTreeTest();
	return 0;
}