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
	if (ps->top == ps->capacity)											//�ж�ջ�������Ƿ�Ϊ0
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;			//������Ϊ0����4������,�������뵱ǰ������2��
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);	//�����������������ڴ�
		if (tmp == NULL)													//�ж��ڴ������Ƿ�ɹ�
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;														//����ָ��ָ��������ڴ�
		ps->capacity = newCapacity;											//����ջ������
	}
	ps->a[ps->top] = x;														//�����ݲ��뵽ջ��
	ps->top++;																//����ջ��λ��
}

void stackPop(ST* ps)
{
	assert(ps);
	if (stackEmpty(ps))
	{
		printf("ջ�в���������!\n");
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
		printf("����ջ��Ԫ��ʧ��!\n");
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
	��ӡջԪ�ر����ӡջ��Ԫ�غ������ջ�ٴ�ӡ�µ�ջ��Ԫ��

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