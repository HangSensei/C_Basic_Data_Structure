#include "list.h"

void test01()
{
	/*LTNode* plist = NULL;
	LTInit(&plist);*/
	LTNode* plist = LTInit();
	//β��
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	//ͷ��
	LTPushFront(plist, 3);
	LTPushFront(plist, 4);
	LTPrint(plist);
	//βɾ
	LTPopBack(plist);
	LTPrint(plist);
	LTPopBack(plist);
	LTPrint(plist);
	//ͷɾ
	LTPopFront(plist);
	LTPrint(plist);
	//����
	LTNode* find = LTFind(plist, 3);
	if (find == NULL)
	{
		printf("DNE! \n");
	}
	else
	{
		printf("Found It !\n");
	}
	//ָ�����
	LTInsertAfter(find, 100);
	LTPrint(plist);
	//ָ��ǰ��
	LTInsertBefore(find, -100);
	LTPrint(plist);
	//ɾ��ָ��λ��
	LTErase(find);
	LTPrint(plist);
	//�ֶ��ÿ�
	find = NULL;

	//��������
	LTDestroy(plist);
	plist = NULL;
}

int main()
{
	test01();
	return 0;
}