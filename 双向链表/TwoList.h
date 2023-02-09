#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

//���������޷���������,˫�������������
//�ڵ������
struct Node
{
	int data;
	struct Node* front;//�ڵ��ǰָ��(��)
	struct Node* next; //�ڵ�ĺ�ָ��(��)
};

//�ٷ�װ����:����һ�ֽṹ(����)���ص�
//ÿ�������нڵ�ĸ����Լ���һ�������һ���ڵ�(˫������)
struct List
{
	//����Ͳ���
	int size;//�ڵ����-Ϊ�������С���ж������Ƿ�Ϊ��׼��
	//ͷָ����ָ����ָ���һ������ָ�룬��������ͷ��㣬����ָ��ͷ����ָ��
	struct Node* firstNode;//��һ���ڵ�
	struct Node* lastNode;//���һ���ڵ�
};
//��ͷ������
void insertNodeHead(struct List* list, int data);

//�����ڵ�
struct Node* createNode(int data);

//����˫������
struct List* createList();

//��β������
void insertNodeTail(struct List* list, int data);

//��ӡ����
//ǰָ���ӡ(˳���ӡ)
void printListFront(struct List* list);

//��ָ���ӡ(�����ӡ)
void printListNext(struct List* list);

//ָ��λ�ò���
/*Ҫ���������,Ҫ���������,Ҫ�����λ��*/
void findNodeinsert(struct List* list, int data, int posData);
