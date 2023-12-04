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

	//pq->head == NULL��ʾ������û�нڵ�
	if (pq->head == NULL)
	{
		//ͷָ���βָ�붼ָ���½ڵ�
		pq->head = pq->tail = newNode;
	}
	//����˵���������Ѿ�������һ���ڵ���
	else
	{
		//ԭβָ���nextָ��ָ���½ڵ�
		pq->tail->next = newNode;
		//��βָ��ָ���µ�β�ڵ�
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
	//�������Ԫ��ɾ������ͷβָ�붼Ҫָ���
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
	printf("��ӡ���\n");
}