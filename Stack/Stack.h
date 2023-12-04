#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//����ջ��ʵ��

typedef char STDataType;

typedef struct Stack
{
	STDataType* a;		//����--������������
	int top;			//ջ��
	int capacity;		//ջ������
}ST;

//ջ�ĳ�ʼ��
void StackInit(ST* ps);

//ջ�Ĵݻ�
void stackDestroy(ST* ps);

//ջԪ�صĲ���
void stackPush(ST* ps, STDataType x);

//ջԪ�ص�ɾ��
void stackPop(ST* ps);

//�ж�ջ��Ԫ�ظ���
int stackSize(ST* ps);

//����ջ������
STDataType stackTop(ST* ps);

//�ж�ջ�Ƿ�Ϊ��
bool stackEmpty(ST* ps);

//��ӡջ��Ԫ��
void printStackTop(ST* ps);