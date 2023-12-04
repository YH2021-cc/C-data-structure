#include"Stack.h"

void testStack()
{
	ST st;
	StackInit(&st);
	printStackTop(&st);

	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
}

//ʹ��ջ�������Ч������(����ƥ��)--���������͸�Ϊchar
//����:������������ž���ջ,�������������,�ͽ�ջ��Ԫ�س�ջ����ƥ��
bool isValid(char* s)
{
	//����ջ
	ST st;
	//��ʼ��ջ
	StackInit(&st);
	//���*s!='\0'�ͼ���ѭ��
	while (*s)
	{
		//���*s=(,[,{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			//������ջ
			stackPush(&st, *s);
			//ָ���ַ�������һ���ַ�
			++s;
		}
		//����
		else
		{
			//����������,����ջ��������
			//˵��ǰ��û��������,��ƥ��,����false
			if (stackEmpty(&st))
			{
				stackDestroy(&st);
				return false;
			}
			//��ȡջ��Ԫ��
			STDataType top = stackTop(&st);
			//ɾ��ջ��Ԫ��
			stackPop(&st);
			//����������Ų�ƥ��
			if ((*s == '}' && top != '{')
				|| (*s == ']' && top != '[')
				|| (*s == ')' && top != '('))
			{
				//����ջ
				stackDestroy(&st);
				return false;
			}
			else
			{
				++s;
			}
		}
	}
	//���ջ���ǿ�˵��ջ�л���������δ��ջ,û��ƥ��
	bool ret = stackEmpty(&st);
	stackDestroy(&st);
	return ret;
}
int main()
{
	if (!isValid("(]"))
	{
		printf("ƥ��ʧ��!\n");
	}
	return 0;
}