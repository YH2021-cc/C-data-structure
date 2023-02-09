#include"List.h"

int main()
{
	List* list = createList();
	push_Back(list, 1);
	push_Back(list, 2);
	print_ZList(list);
	print_NList(list);
	pop_Back(list);
	//clear(list);
	print_ZList(list);

	return 0;
}