#include "SeqList.h"

void test()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPushBack(&sl, 5);

	SLPushFront(&sl, 0);
	SLPrint(&sl);

	SLPopBack(&sl);
	SLPrint(&sl);

	SLPopFront(&sl);
	SLPrint(&sl);

	SLInsert(&sl, 3, 250);
	SLPrint(&sl);

	SLErase(&sl, 3);
	SLPrint(&sl);

	SLDestroy(&sl);
}

int main()
{
	test();
	return 0;
}