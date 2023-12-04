#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<assert.h>

//������ͷ��������ʵ���Ƕ���ڵ�����(һ��������Ƕ���ڵ����)

//�ڵ�����
typedef int Data;

//����--ʵ���Ǹ��ձ��һ�β���Ľڵ�Ϊ��һ���ڵ�
typedef struct Node
{
	Data data;
	struct Node* next;
}ListNode;

//�����ڵ㺯��
ListNode* CreateNode(Data x);

//β�巨
void PushBack(ListNode** list, Data x);

//ͷ�巨
void PushFront(ListNode** list, Data x);

//βɾ��
void PopBack(ListNode** list);

//ͷɾ��
void PopFront(ListNode** list);

//��������ɾ��Ԫ��-x:����x��ɾ���ڵ�
void Erase(ListNode** list, Data x);

//��������
void PrintList(ListNode* list);

//�ж������Ƿ�Ϊ��
bool Empty(ListNode** list);

//ͳ�ƽڵ����
int Size(ListNode** list);
