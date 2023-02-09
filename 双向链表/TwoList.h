#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

//单向链表无法逆序数据,双向链表可以逆序
//节点的属性
struct Node
{
	int data;
	struct Node* front;//节点的前指针(左)
	struct Node* next; //节点的后指针(右)
};

//再封装链表:描述一种结构(链表)的特点
//每个链表都有节点的个数以及第一个和最后一个节点(双向链表)
struct List
{
	//万金油参数
	int size;//节点个数-为求链表大小和判断链表是否为空准备
	//头指针是指链表指向第一个结点的指针，若链表有头结点，则是指向头结点的指针
	struct Node* firstNode;//第一个节点
	struct Node* lastNode;//最后一个节点
};
//表头法插入
void insertNodeHead(struct List* list, int data);

//创建节点
struct Node* createNode(int data);

//创建双向链表
struct List* createList();

//表尾法插入
void insertNodeTail(struct List* list, int data);

//打印函数
//前指针打印(顺序打印)
void printListFront(struct List* list);

//后指针打印(逆序打印)
void printListNext(struct List* list);

//指定位置插入
/*要插入的链表,要插入的数据,要插入的位置*/
void findNodeinsert(struct List* list, int data, int posData);
