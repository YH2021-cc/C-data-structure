#include"List.h"
#include<stdlib.h>
//ͷ��ͷɾ
void testFront(List* list)
{
	printf("����--------\n");
	push_Front(list, 1);
	push_Front(list, 2);
	push_Front(list, 3);
	print_ZList(list);
	printf("ɾ��--------\n");
	//pop_Front(list);
	erase(list);
	printf("%d\n", list->size);
	print_ZList(list);
}

//β��βɾ
void testBack(List* list)
{
	printf("����--------\n");
	push_Back(list, 1);
	push_Back(list, 2);
	push_Back(list, 3);
	print_ZList(list);
	printf("ɾ��--------\n");
	pop_Back(list);
	print_ZList(list);
}
int main()
{
	List* list = createList();

	testBack(list);
	erase(list);
	//print_ZList(list);
	//testFront(list);

	system("pause");
	//��������
	clear(list);
	free(list);
	return 0;
}