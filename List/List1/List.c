#include "List.h"
#include<string.h>
#include "List.h"
#include "List.h"
Node* createNode(Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("创建节点失败!\n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

Node* createHead()
{
	Node* headNode = (Node*)malloc(sizeof(Node));
	if (headNode == NULL)
	{
		printf("创建链表表头失败!\n");
		return;
	}
	headNode->data.id = 0;
	strcpy(headNode->data.name, "");
	headNode->next = NULL;
	return headNode;
}

List* createList()
{
	List* newList = (List*)malloc(sizeof(List));
	if (newList == NULL)
	{
		printf("创建链表失败!\n");
		return;
	}
	newList->size = 0;
	newList->head = createHead();

	return newList;
}

void insertHead(List* list, Data data)
{
	Node* newNode = createNode(data);
	if (newNode == NULL)
	{
		printf("插入节点时创建节点失败!\n");
		return;
	}
	newNode->next = list->head->next;
	list->head->next = newNode;
	++list->size;
}

void printList(List* list)
{
	if (empty(list))
	{
		printf("链表为空无法打印!\n");
		return;
	}
	Node* nodePtr = list->head->next;
	while (nodePtr)
	{
		printf("%d\t%s\n", nodePtr->data.id, nodePtr->data.name);
		nodePtr = nodePtr->next;
	}
	printf("打印成功!\n");
}

bool empty(List* list)
{
	return list->size == 0 ? true : false;
}

int size(List* list)
{
	return list->size;
}

void deleteNode(List* list, int id)
{
	Node* deleteNodeLeft = list->head;
	Node* deletePosNode = list->head->next;
	while (deletePosNode != NULL && deletePosNode->data.id != id)
	{
		deleteNodeLeft = deletePosNode;
		deletePosNode = deletePosNode->next;
	}
	if (deletePosNode == NULL)
	{
		printf("数据不存在!\n");
		return;
	}
	else
	{
		deleteNodeLeft->next = deletePosNode->next;
		free(deletePosNode);
		deletePosNode = NULL;
		--list->size;
		printf("删除成功!\n");
	}
}

void findData(List* list, int id)
{
	Node* posNode = list->head->next;
	if (!findOrModify(posNode, id))return;
	printf("%d\t%s\n", posNode->data.id, posNode->data.name);
}

void modifyData(List* list, int id)
{
	Node* posNode = list->head->next;
	if (!findOrModify(posNode, id))return;
	while (1)
	{
		printf("你想修改什么?----1 id 2 姓名: ");
		int choose = inputInt();

		switch (choose)
		{
		case 1:
			int newId = inputInt();
			posNode->data.id = newId;
			break;
		case 2:
			char newName[10] = { 0 };
			strcpy(posNode->data.name, inputStr(newName));
			break;
		}
		printf("是否继续修改?--1 是 2 否: ");
		int choose1 = inputInt();
		if (2 == choose1)
			break;
	}
}

int findOrModify(Node* node, int id)
{
	while (node != NULL && node->data.id != id)
	{
		node = node->next;
	}
	if (node == NULL)
	{
		printf("数据不存在!\n");
		return 0;
	}
	return 1;
}

char* inputStr()
{
	char newData[10] = { 0 };
	scanf("%[^\n]"); scanf("%*c");		//清空输入缓冲区
	scanf("%s", newData);
	return newData;
}

int inputInt()
{
	int temp;
	scanf("%[^\n]"); scanf("%*c");		//清空输入缓冲区
	scanf("%d", &temp);
	return temp;
}