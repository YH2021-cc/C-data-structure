#include "Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void stackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void stackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)											//判断栈的容量是否为0
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;			//当容量为0申请4个容量,否则申请当前容量的2倍
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);	//申请新容量的数据内存
		if (tmp == NULL)													//判断内存申请是否成功
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;														//数据指针指向申请的内存
		ps->capacity = newCapacity;											//更新栈的容量
	}
	ps->a[ps->top] = x;														//将数据插入到栈顶
	ps->top++;																//更新栈顶位置
}

void stackPop(ST* ps)
{
	assert(ps);
	if (stackEmpty(ps))
	{
		printf("栈中不存在数据!\n");
		return;
	}
	ps->top--;
}

int stackSize(ST* ps)
{
	return ps->top;
}

STDataType stackTop(ST* ps)
{
	assert(ps);
	if (stackEmpty(ps))
	{
		printf("返回栈顶元素失败!\n");
		return;
	}
	return ps->a[ps->top - 1];
}

bool stackEmpty(ST* ps)
{
	assert(ps);
	return stackSize(ps) == 0;
}

/*
	打印栈元素必须打印栈顶元素后让其出栈再打印新的栈顶元素

*/
void printStackTop(ST* ps)
{
	assert(ps);
	while (!stackEmpty(ps))
	{
		printf("%d ", stackTop(ps));
		stackPop(ps);
	}
}