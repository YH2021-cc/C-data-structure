#include"List1.h"

int main()
{
	//����������
	ListNode* list = NULL;

	//����Ԫ��
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);

	////ɾ��Ԫ��
	//PopFront(&list);
	//PopFront(&list);

	//if (!Empty(&list))
	//	printf("buweik");

	////��ӡ
	//PrintList(list);

	printf("�ڵ������: %d\n", Size(&list));
	return 0;
}