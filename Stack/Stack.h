#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//数组栈的实现

typedef char STDataType;

typedef struct Stack
{
	STDataType* a;		//数据--当做数组来用
	int top;			//栈顶
	int capacity;		//栈的容量
}ST;

//栈的初始化
void StackInit(ST* ps);

//栈的摧毁
void stackDestroy(ST* ps);

//栈元素的插入
void stackPush(ST* ps, STDataType x);

//栈元素的删除
void stackPop(ST* ps);

//判断栈的元素个数
int stackSize(ST* ps);

//返回栈顶数据
STDataType stackTop(ST* ps);

//判断栈是否为空
bool stackEmpty(ST* ps);

//打印栈顶元素
void printStackTop(ST* ps);