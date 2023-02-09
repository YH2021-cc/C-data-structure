#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

//����
typedef struct data
{
	int id;
	char name[10];
}Data;

//�ڵ�����
typedef struct Node
{
	Data data;
	struct Node* next;
}Node;

//�����ڵ�
Node* createNode(Data data);

//����
typedef struct list
{
	int size;

	//�����ͷ
	Node* head;
}List;

//������ͷ����
Node* createHead();

//��������
List* createList();

//��ͷ������
void insertHead(List* list, Data data);

//��ӡ����(ͷ��)
void printList(List* list);

//�ж������Ƿ�Ϊ��
bool empty(List* list);

//�жϽڵ����
int size(List* list);

//�ڵ�ɾ��(id)--ͷɾ��
void deleteNode(List* list, int id);

//��ѯ����(id)
void findData(List* list, int id);

//�޸�����(id)
void modifyData(List* list, int id);

//�����޸ĺͲ�ѯ��ͬ����
int findOrModify(Node* node, int id);

//����scanf-����
int inputInt();

//����scanf-�ַ���
char* inputStr();
