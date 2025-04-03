#pragma once
#include<stdio.h>
#include<stdlib.h>

//������ʽ�ṹ�Ķ�����
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//ǰ��
void preOrder(BTNode* root);
//����
void inOrder(BTNode* root);
//����
void postOrder(BTNode* root);
//�������ڵ����
int BinaryTreeSize(BTNode* root);
//�������ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
//��������K��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
//�����������/�߶�
int BinaryTreeDepth(BTNode* root);
//����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//����������
void BinaryTreeDestroy(BTNode** root);
//�������
void levelOrder(BTNode* root);