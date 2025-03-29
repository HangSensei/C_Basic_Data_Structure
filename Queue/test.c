#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

void test01()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	//QueuePop(&q);
	int front = QueueFront(&q);
	int rear = QueueBack(&q);
	int size = QueueSize(&q);
	printf("front:%d\n",front);
	printf("rear:%d\n", rear);
	printf("size:%d\n", size);


}


int main()
{
	test01();
	return 0;
}