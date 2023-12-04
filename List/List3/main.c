#include"List.h"
#include<stdlib.h>
//Í·²åÍ·É¾
void testFront(List* list)
{
	printf("²åÈë--------\n");
	push_Front(list, 1);
	push_Front(list, 2);
	push_Front(list, 3);
	print_ZList(list);
	printf("É¾³ı--------\n");
	//pop_Front(list);
	erase(list);
	printf("%d\n", list->size);
	print_ZList(list);
}

//Î²²åÎ²É¾
void testBack(List* list)
{
	printf("²åÈë--------\n");
	push_Back(list, 1);
	push_Back(list, 2);
	push_Back(list, 3);
	print_ZList(list);
	printf("É¾³ı--------\n");
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
	//Ïú»ÙÁ´±í
	clear(list);
	free(list);
	return 0;
}