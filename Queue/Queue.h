#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//队列数据类型
typedef int QDataType;

//队列节点
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

//创建队列节点函数
QNode* createQueueNode(QDataType data);

//队列
typedef struct Queue
{
	QNode* head;	//头指针指向队列的头节点
	QNode* tail;	//尾指针指向队列的尾节点
	int size;
}Queue;

//队列的初始化
void QueueInit(Queue* pq);

//队列的销毁
void QueueDestroy(Queue* pq);

//插入数据(尾插)
void QueuePush(Queue* pq, QDataType x);

//删除数据(头删)
void QueuePop(Queue* pq);

//取队头数据
QDataType QueueFront(Queue* pq);

//取队尾数据
QDataType QueueBack(Queue* pq);

//判断队列是否为空
bool QueueEmpty(Queue* pq);

//返回队列元素个数
int QueueSize(Queue* pq);

//打印队列元素
void printQueueData(Queue* pq);