#include <stdio.h>
#include <stdlib.h>
#include "List.h"

/*
	有头链表
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
			printf("插入数据\n");
			scanf("%[^\n]");
			scanf("%*c"); // 清空输入缓冲区
			scanf("%d%s", &temp.id, temp.name);
			insertHead(list, temp);
			break;
		case 1:
			printList(list);
			break;
		case 2:
			printf("请输入要删除的id: ");
			int temp2 = inputInt();
			deleteNode(list, temp2);
			break;
		case 3:
			printf("请输入要查找的id: ");
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