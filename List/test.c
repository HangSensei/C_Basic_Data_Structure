#include "list.h"

void test01()
{
	/*LTNode* plist = NULL;
	LTInit(&plist);*/
	LTNode* plist = LTInit();
	//尾插
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	//头插
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);
	LTPrint(plist);
	//尾删
	LTPopBack(plist);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);
	//头删
	LTPopFront(plist);
	LTPrint(plist);
	//查找
	LTNode* find = LTFind(plist, 3);
	if (find == NULL)
	{
		printf("DNE! \n");
	}
	else
	{
		printf("Found It !\n");
	}
	//指定后插
	LTInsertAfter(find, 100);
	LTPrint(plist);
	//指定前插
	LTInsertBefore(find, -100);
	LTPrint(plist);
	//删除指定位置
	LTErase(find);
	LTPrint(plist);
	//手动置空
	find = NULL;

	//销毁链表
	LTDestroy(plist);
	plist = NULL;
}

int main()
{
	test01();
	return 0;
}