#include "TwoList.h"

//创建节点
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	assert(newNode);//如果申请失败返回空
	newNode->data = data;
	newNode->front = newNode->next = NULL;
	return newNode;
}

//创建双向链表
struct List* createList()
{
	//申请内存
	struct List* list = (struct List*)malloc(sizeof(struct List));
	//初始化链表
	assert(list);
	list->firstNode = list->lastNode = NULL;
	list->size = 0;
	return list;
}

/*要在哪个链表插入,插入的数据*/
void insertNodeHead(struct List* list, int data)
{
	struct Node* newNode = createNode(data);
	if (list->firstNode == NULL)
	{
		list->lastNode = newNode;
	}
	else
	{
		list->firstNode->front = newNode;
		newNode->next = list->firstNode;
	}
	list->firstNode = newNode;//改变表头位置
	list->size++;
}

//表尾法插入
void insertNodeTail(struct List* list, int data)
{
	struct Node* newNode = createNode(data);
	if (list->lastNode == NULL)
	{
		list->firstNode = newNode;
	}
	else
	{
		list->lastNode->front = newNode;
		newNode->next = list->lastNode;
	}
	list->lastNode = newNode;//改变表尾位置
	list->size++;
}

//打印函数
//前指针打印(顺序打印)
void printListFront(struct List* list)
{
	if (list->size == 0)
		printf("链表为空,无法打印!\n");
	else
	{
		struct Node* p = list->lastNode;
		while (p)
		{
			printf("%d\t", p->data);
			p = p->front;
		}
		printf("\n");
	}
}

//后指针打印(逆序打印)
void printListNext(struct List* list)
{
	if (list->size == 0)
		printf("链表为空,无法打印!\n");
	else
	{
		struct Node* p = list->firstNode;
		while (p)
		{
			printf("%d\t", p->data);
			p = p->next;
		}
		printf("\n");
	}
}

//指定位置插入
/*要插入的链表,要插入的数据,要插入的位置*/
void findNodeinsert(struct List* list, int data, int posData)
{
	if (list->size == 0)
	{
		printf("链表为空,无法插入!\n");
		return;
	}
	else if (list->firstNode->data == posData)
	{
		insertNodeHead(list, data);
	}
	else
	{
		struct Node* posNode = list->firstNode->next;
		struct Node* posNodeleft = list->firstNode;
		while (posNode != NULL && posNode->data != data)
		{
			posNodeleft = posNode;
			posNode = posNodeleft->next;
		}
		if (posNode == NULL)
		{
			printf("未找到指定位置,无法插入!\n");
		}
		else
		{
			struct Node* newNode = createNode(data);
			posNodeleft->next = newNode;
			newNode->front = posNodeleft;
			newNode->next = posNode;
			posNode->front = newNode;
		}
	}
}