#pragma once
#include<stdio.h>
#include<stdlib.h>

//定义链式结构的二叉树
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//前序
void preOrder(BTNode* root);
//中序
void inOrder(BTNode* root);
//后序
void postOrder(BTNode* root);
//二叉树节点个数
int BinaryTreeSize(BTNode* root);
//二叉树子节点个数
int BinaryTreeLeafSize(BTNode* root);
//二叉树第K层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
//二叉树的深度/高度
int BinaryTreeDepth(BTNode* root);
//二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//二叉树销毁
void BinaryTreeDestroy(BTNode** root);
//层序遍历
void levelOrder(BTNode* root);