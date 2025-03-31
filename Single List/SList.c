#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//����Ĵ�ӡ
void SLTPrint(SLTNode* phead)//node1�ڵ�ĵ�ַ��ȷ��pheadʼ��ָ���һ���ڵ�
{
	SLTNode* pcur = phead;//node1�ڵ�ĵ�ַ��pcur
	while (pcur != NULL)
	{
		printf("%d -> ", pcur->data);//node1->data ��1 ->��
		pcur = pcur->next;//����һ���ڵ�ĵ�ַ��ֵ��pcur ��pcurָ��ĵ�ַ���£�
	}
	printf("NULL\n");//�������example����1 -> 2 -> 3 -> 4 -> NULL��
}

SLTNode* SLTbuyNode(SLTDatatype x)
{
	//����x�����ڵ�
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));//���ٿռ�
	if (newnode == NULL)
	{
		perror("malloc fail!");//malloc������
		exit(1);
	}
	newnode->data = x;//data��ֵx
	newnode->next = NULL;//��һ���ڵ��ַΪNULL��β�ڵ㲻������һ���ڵ㣩

	return newnode;//���ش����ڵ�ĵ�ַ
}

//����β��
void SLTPushBack(SLTNode** pphead, SLTDatatype x)
{
	//�����½ڵ�
	SLTNode* newnode = SLTbuyNode(x);
	//����Ϊ��
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//Ѱ��β�ڵ�
		SLTNode* ptail = *pphead;//�׸��ڵ��ַ��ֵ��Ѱ��β����ָ�����,�Ա����ptail����
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}
		//�ҵ���β�ڵ�
		ptail->next = newnode;
	}
}

//����βɾ
void SLTPopBack(SLTNode** pphead)
{
	//���β���Ϊ�գ����ܴ�������
	assert(pphead && *pphead);
	//ֻ��һ���ڵ�������
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//��ֹһ���ڵ�������
	else
	{
		//��prev��ptail
		SLTNode* ptail = *pphead;
		SLTNode* prev = NULL;
		while (ptail->next != NULL)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		//�ҵ���prev��ptail
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}

//����ͷ��
void SLTPushFront(SLTNode** pphead, SLTDatatype x)
{
	assert(pphead != NULL);
	SLTNode* newnode = SLTbuyNode(x);

	newnode->next = *pphead;
	//����ͷ�ڵ��ַ����
	*pphead = newnode;
}
//����ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//�������
SLTNode* SLTFind(SLTNode* phead, SLTDatatype x)
{
	SLTNode* pcur = phead;
	while (pcur != NULL)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDatatype x)
{
	assert(pphead && pos);
	//��posָ���һ���ڵ㣬��ͷ��
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = SLTbuyNode(x);
		//��posǰһ���ڵ�
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//prev newnode pos
		prev->next = newnode;
		newnode->next = pos;
	}
}
//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDatatype x)
{
	assert(pos);
	SLTNode* newnode = SLTbuyNode(x);
	//pos newnode pos->next
	newnode->next = pos->next;
	pos->next = newnode;
}

//ɾ��pos���
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && pos);
	//pos����ͷ���
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		//prev pos
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//prev pos pos->next
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//ɾ��pos֮��Ľ��
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);
	// pos del = pos->next pos->next-next
	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

//��������
void SListDestroy(SLTNode** pphead)
{
	SLTNode* pcur = *pphead;
	while (pcur != NULL)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}