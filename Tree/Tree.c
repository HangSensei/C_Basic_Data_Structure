#define _CRT_SECURE_NO_WARNINGS
#include "Tree.h"
#include "Queue.h"

void preOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	inOrder(root->left);
	printf("%c ", root->data);
	inOrder(root->right);
}

void postOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%c ", root->data);
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k-1) + BinaryTreeLevelKSize(root->right, k-1);
}

int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDep = BinaryTreeDepth(root->left);
	int rightDep = BinaryTreeDepth(root->right);
	return 1 + (leftDep > rightDep ? leftDep : rightDep);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* leftFind = BinaryTreeFind(root->left, x);
	if (leftFind)
	{
		return leftFind;
	}
	BTNode* rightFind = BinaryTreeFind(root->right, x);
	if (rightFind)
	{
		return rightFind;
	}
	return NULL;
}

void BinaryTreeDestroy(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestroy(&(*root)->left);
	BinaryTreeDestroy(&(*root)->right);
	free(*root);
	*root = NULL;
}

void levelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);//root存储在队列里
	while (!QueueEmpty(&q))//只要队列不为空
	{
		//取队头，出队头
		BTNode* top = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", top->data);
		//将队头非空节点左右子节点入队列
		if (top->left)
		{
			QueuePush(&q, top->left);
		}
		if (top->right)
		{
			QueuePush(&q, top->right);
		}
	}
	QueueDestroy(&q);
}