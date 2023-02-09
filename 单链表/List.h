#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

//数据
typedef struct data
{
	int id;
	char name[10];
}Data;

//节点属性
typedef struct Node
{
	Data data;
	struct Node* next;
}Node;

//创建节点
Node* createNode(Data data);

//链表
typedef struct list
{
	int size;

	//链表表头
	Node* head;
}List;

//创建表头函数
Node* createHead();

//创建链表
List* createList();

//表头法插入
void insertHead(List* list, Data data);

//打印链表(头打法)
void printList(List* list);

//判断链表是否为空
bool empty(List* list);

//判断节点个数
int size(List* list);

//节点删除(id)--头删法
void deleteNode(List* list, int id);

//查询数据(id)
void findData(List* list, int id);

//修改数据(id)
void modifyData(List* list, int id);

//整合修改和查询相同代码
int findOrModify(Node* node, int id);

//整合scanf-整数
int inputInt();

//整合scanf-字符串
char* inputStr();
