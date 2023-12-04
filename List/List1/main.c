#include <stdio.h>
#include <stdlib.h>
#include "List.h"

/*
	��ͷ����
*/

int main()
{
	List *list = createList();
	int choose = 0;
	Data temp = {0, ""};
	while (1)
	{
		scanf("%d", &choose);
		switch (choose)
		{
		case 0:
			printf("��������\n");
			scanf("%[^\n]");
			scanf("%*c"); // ������뻺����
			scanf("%d%s", &temp.id, temp.name);
			insertHead(list, temp);
			break;
		case 1:
			printList(list);
			break;
		case 2:
			printf("������Ҫɾ����id: ");
			int temp2 = inputInt();
			deleteNode(list, temp2);
			break;
		case 3:
			printf("������Ҫ���ҵ�id: ");
			int temp1 = inputInt();
			findData(list, temp1);
			break;
		case 4:
			int temp3 = inputInt();
			modifyData(list, temp3);
			break;
		case 9:
			exit(0);
		}
	}

	return 0;
}