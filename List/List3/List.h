#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<malloc.h>
typedef int ListData;	//链表的数据的类型(测试)

struct Preson			//更换数据类型将int换成struct Preson即可
{
	char name[10];
	int id;
	int age;
	//...
};

//节点
typedef struct Node
{
	ListData data;
	struct Node* front;
	struct Node* next;
}Node;

//创建节点函数
Node* createNode(ListData data);

//链表
typedef struct List
{
	int size;
	Node* head;
}List;

//创建链表头节点函数
Node* createListHeadNode();

//创建链表函数
List* createList();

//尾插法
void push_Back(List* list, ListData data);

//尾删法
void pop_Back(List* list);

//头插法
void push_Front(List* list, ListData data);

//头删法
void pop_Front(List* list);

//链表打印
//正序
void print_ZList(List* list);

//逆序
void print_NList(List* list);

//返回链表的节点个数
int getListNodeSize(List* list);

//判断链表是否为空--为空打印并结束
void emptyList(List* list);

//清空链表
void clear(List* list);

//以id查找链表中的符合数据
Node* find_List(List* list);

//任意位置插入链表
void insert(List* list, ListData data);

//任意位置删除链表节点
void erase(List* list);
