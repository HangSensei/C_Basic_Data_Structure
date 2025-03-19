#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void test01()
{
	//手动创建节点，用malloc为节点开辟空间
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	//存入数据
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	//当前节点的next指针指向下一个结构体的地址(指针)
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	//尾部节点的next指针指向NULL（因为后续没有节点了）
	node4->next = NULL;
	//定义plist指针变量指向第一个节点的地址
	SLTNode* plist = node1;
	//打印单链表测试
	SLTPrint(plist);//传plist的值（node1节点的地址）
}

void test02()
{
	//创建空链表
	SLTNode* plist = NULL;//未开辟空间，所以为空
	SLTPrint(plist);

	//尾插
	SLTPushBack(&plist, 1);//传址，确保操作的是同一块空间
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

	//头插
	//SLTPushFront(&plist, 1);//传址，确保操作的是同一块空间
	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 3);
	//SLTPushFront(&plist, 4);
	//SLTPrint(plist);

	//尾删
	/*SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPrint(plist);*/

	//头删
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPrint(plist);

}

int main()
{
	//test01();
	test02();
	return 0;
}