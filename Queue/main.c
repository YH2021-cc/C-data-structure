//��ʽ����--��������ͷ
#include"Queue.h"

void testQueue()
{
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, 1);
	QueuePush(&qu, 2);
	QueuePush(&qu, 3);

	printQueueData(&qu);
	QueueDestroy(&qu);
}

int main()
{
	testQueue();
	return 0;
}