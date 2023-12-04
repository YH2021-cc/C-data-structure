#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//������������
typedef int QDataType;

//���нڵ�
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

//�������нڵ㺯��
QNode* createQueueNode(QDataType data);

//����
typedef struct Queue
{
	QNode* head;	//ͷָ��ָ����е�ͷ�ڵ�
	QNode* tail;	//βָ��ָ����е�β�ڵ�
	int size;
}Queue;

//���еĳ�ʼ��
void QueueInit(Queue* pq);

//���е�����
void QueueDestroy(Queue* pq);

//��������(β��)
void QueuePush(Queue* pq, QDataType x);

//ɾ������(ͷɾ)
void QueuePop(Queue* pq);

//ȡ��ͷ����
QDataType QueueFront(Queue* pq);

//ȡ��β����
QDataType QueueBack(Queue* pq);

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

//���ض���Ԫ�ظ���
int QueueSize(Queue* pq);

//��ӡ����Ԫ��
void printQueueData(Queue* pq);