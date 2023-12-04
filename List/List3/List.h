#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<malloc.h>
typedef int ListData;	//��������ݵ�����(����)

struct Preson			//�����������ͽ�int����struct Preson����
{
	char name[10];
	int id;
	int age;
	//...
};

//�ڵ�
typedef struct Node
{
	ListData data;
	struct Node* front;
	struct Node* next;
}Node;

//�����ڵ㺯��
Node* createNode(ListData data);

//����
typedef struct List
{
	int size;
	Node* head;
}List;

//��������ͷ�ڵ㺯��
Node* createListHeadNode();

//����������
List* createList();

//β�巨
void push_Back(List* list, ListData data);

//βɾ��
void pop_Back(List* list);

//ͷ�巨
void push_Front(List* list, ListData data);

//ͷɾ��
void pop_Front(List* list);

//�����ӡ
//����
void print_ZList(List* list);

//����
void print_NList(List* list);

//��������Ľڵ����
int getListNodeSize(List* list);

//�ж������Ƿ�Ϊ��--Ϊ�մ�ӡ������
void emptyList(List* list);

//�������
void clear(List* list);

//��id���������еķ�������
Node* find_List(List* list);

//����λ�ò�������
void insert(List* list, ListData data);

//����λ��ɾ������ڵ�
void erase(List* list);
