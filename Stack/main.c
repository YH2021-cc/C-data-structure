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

//使用栈来解决有效的括号(括号匹配)--将数据类型改为char
//方法:如果遇到左括号就入栈,如果遇到右括号,就将栈顶元素出栈进行匹配
bool isValid(char* s)
{
	//创建栈
	ST st;
	//初始化栈
	StackInit(&st);
	//如果*s!='\0'就继续循环
	while (*s)
	{
		//如果*s=(,[,{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			//将它入栈
			stackPush(&st, *s);
			//指向字符串的下一个字符
			++s;
		}
		//否则
		else
		{
			//遇到右括号,但是栈内无数据
			//说明前面没有左括号,不匹配,返回false
			if (stackEmpty(&st))
			{
				stackDestroy(&st);
				return false;
			}
			//获取栈顶元素
			STDataType top = stackTop(&st);
			//删除栈顶元素
			stackPop(&st);
			//如果左右括号不匹配
			if ((*s == '}' && top != '{')
				|| (*s == ']' && top != '[')
				|| (*s == ')' && top != '('))
			{
				//销毁栈
				stackDestroy(&st);
				return false;
			}
			else
			{
				++s;
			}
		}
	}
	//如果栈不是空说明栈中还有左括号未出栈,没有匹配
	bool ret = stackEmpty(&st);
	stackDestroy(&st);
	return ret;
}
int main()
{
	if (!isValid("(]"))
	{
		printf("匹配失败!\n");
	}
	return 0;
}