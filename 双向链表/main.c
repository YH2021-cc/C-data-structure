#include<stdio.h>

#include"TwoList.h"

/*
	��ͷ˫���ѭ��������Ȼû�����ñ�ͷ����ʵ�ǰѵ�һ����㵱��ͷ����������
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