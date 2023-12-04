#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<assert.h>

//不带表头的链表其实就是多个节点的组合(一个链表就是多个节点组成)

//节点数据
typedef int Data;

//链表--实际是个空表第一次插入的节点为第一个节点
typedef struct Node
{
	Data data;
	struct Node* next;
}ListNode;

//创建节点函数
ListNode* CreateNode(Data x);

//尾插法
void PushBack(ListNode** list, Data x);

//头插法
void PushFront(ListNode** list, Data x);

//尾删法
void PopBack(ListNode** list);

//头删法
void PopFront(ListNode** list);

//根据条件删除元素-x:根据x来删除节点
void Erase(ListNode** list, Data x);

//遍历链表
void PrintList(ListNode* list);

//判断链表是否为空
bool Empty(ListNode** list);

//统计节点个数
int Size(ListNode** list);
