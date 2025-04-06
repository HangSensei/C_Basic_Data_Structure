#define _CRT_SECURE_NO_WARNINGS
#include "Tree.h"

BTNode* buyNode(char x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	node->data = x;
	node->left = node->right = NULL;
	return node;
}

BTNode* createBinaryTree()
{
	BTNode* nodeA = buyNode('A');
	BTNode* nodeB = buyNode('B');
	BTNode* nodeC = buyNode('C');
	BTNode* nodeD = buyNode('D');
	BTNode* nodeE = buyNode('E');
	BTNode* nodeF = buyNode('F');

	nodeA->left = nodeB;
	nodeA->right = nodeC;
	nodeB->left = nodeD;
	nodeC->left = nodeE;
	nodeC->right = nodeF;
	
	return nodeA;

}

void test01()
{
	BTNode* root = createBinaryTree();
	preOrder(root);
	printf("\n");

	inOrder(root);
	printf("\n");

	postOrder(root);
	printf("\n");

	
	printf("size:%d\n", BinaryTreeSize(root));
	
	printf("Leaf size:%d\n", BinaryTreeLeafSize(root));
	
	printf("K size:%d\n", BinaryTreeLevelKSize(root,3));

	printf("Tree Depth:%d\n", BinaryTreeDepth(root));
	if (BinaryTreeFind(root, 'E'))
	{
		printf("Found it\n");
	}
	else
	{
		printf("DNE\n");
	}
	printf("levelOrder:");
	levelOrder(root);


}

int main()
{
	test01();
	return 0;
}