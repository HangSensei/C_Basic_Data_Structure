#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void test01()
{
	//�ֶ������ڵ㣬��mallocΪ�ڵ㿪�ٿռ�
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));
	//��������
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	//��ǰ�ڵ��nextָ��ָ����һ���ṹ��ĵ�ַ(ָ��)
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	//β���ڵ��nextָ��ָ��NULL����Ϊ����û�нڵ��ˣ�
	node4->next = NULL;
	//����plistָ�����ָ���һ���ڵ�ĵ�ַ
	SLTNode* plist = node1;
	//��ӡ���������
	SLTPrint(plist);//��plist��ֵ��node1�ڵ�ĵ�ַ��
}

void test02()
{
	//����������
	SLTNode* plist = NULL;//δ���ٿռ䣬����Ϊ��
	SLTPrint(plist);

	//β��
	SLTPushBack(&plist, 1);//��ַ��ȷ����������ͬһ��ռ�
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

	//ͷ��
	//SLTPushFront(&plist, 1);//��ַ��ȷ����������ͬһ��ռ�
	//SLTPushFront(&plist, 2);
	//SLTPushFront(&plist, 3);
	//SLTPushFront(&plist, 4);
	//SLTPrint(plist);

	//βɾ
	/*SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPrint(plist);*/

	//ͷɾ
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