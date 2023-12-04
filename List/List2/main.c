#include"List1.h"

int main()
{
	//创建空链表
	ListNode* list = NULL;

	//插入元素
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);

	////删除元素
	//PopFront(&list);
	//PopFront(&list);

	//if (!Empty(&list))
	//	printf("buweik");

	////打印
	//PrintList(list);

	printf("节点个数是: %d\n", Size(&list));
	return 0;
}