#include<stdio.h>

#include"TwoList.h"

/*
	无头双向非循环链表：虽然没有设置表头，其实是把第一个结点当做头结点来处理的
*/

int main()
{
	struct List* list = createList();
	insertNodeHead(list, 1);
	insertNodeHead(list, 2);
	printListFront(list);
	printListNext(list);
	return 0;
}