#include "Queue.h"

QNode* createQueueNode(QDataType data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->size = 0;
	pq->head = pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newNode = createQueueNode(x);

	//pq->head == NULL表示队列里没有节点
	if (pq->head == NULL)
	{
		//头指针和尾指针都指向新节点
		pq->head = pq->tail = newNode;
	}
	//否则说明队列里已经有至少一个节点了
	else
	{
		//原尾指针的next指针指向新节点
		pq->tail->next = newNode;
		//让尾指针指向新的尾节点
		pq->tail = newNode;
	}
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QNode* cur = pq->head->next;
	free(pq->head);
	pq->head = cur;
	//如果队列元素删除完了头尾指针都要指向空
	if (pq->head == NULL)
	{
		pq->tail = NULL;
	}
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return 0 == QueueSize(pq);
}

int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}

void printQueueData(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	while (!QueueEmpty(pq))
	{
		printf("%d ", QueueFront(pq));
		QueuePop(pq);
	}
	printf("打印完毕\n");
}