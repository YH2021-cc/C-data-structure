#include "List.h"

Node* createNode(ListData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode);
	newNode->data = data;
	newNode->front = newNode->next = NULL;
	return newNode;
}

Node* createListHeadNode()
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode);
	newNode->front = newNode->next = newNode;
	return newNode;
}

List* createList()
{
	List* list = (List*)malloc(sizeof(List));
	assert(list);
	list->size = 0;
	list->head = createListHeadNode();
	return list;
}

void push_Back(List* list, ListData data)
{
	Node* newNode = createNode(data);
	assert(newNode);
	Node* tail = list->head->front;			//定义一个节点指针指向尾节点(最初为头节点)
	tail->next = newNode;					//让尾节点(最初为头节点)的next指针指向新节点
	newNode->front = tail;					//让新节点的front指针指向前一个节点(最初为头节点)
	newNode->next = list->head;				//让新节点的next指针指向头节点
	list->head->front = newNode;			//让头节点的front指针指向尾节点(新的节点)
	++list->size;
}

void pop_Back(List* list)
{
	emptyList(list);
	Node* back_Node = list->head->front;		//定义一个节点指针指向链表的尾节点
	back_Node->front->next = list->head;		//使尾节点的前一个节点的next指针指向头节点
	list->head->front = back_Node->front;		//头节点的front指向新的尾节点
	free(back_Node);
	back_Node = NULL;
	--list->size;
}

void push_Front(List* list, ListData data)
{
}

void pop_Front(List* list)
{
	emptyList(list);
}

void print_ZList(List* list)					//正序打印
{
	//判断链表是否为空
	emptyList(list);

	//遍历链表的终止条件是不指向头节点
	Node* print = list->head->next;		//定义一个节点指针指向链表中的第一个节点(非头结点)
	while (print != list->head)
	{
		printf("%d\t\n", print->data);	//打印数据
		print = print->next;			//指向下一个节点
	}
}

void print_NList(List* list)			//逆序打印
{
	//判断链表是否为空
	emptyList(list);
	//遍历链表的终止条件是不指向头节点
	Node* print = list->head->front;		//定义一个节点指针指向尾节点
	while (print != list->head)
	{
		printf("%d\t\n", print->data);		//打印数据
		print = print->front;				//指向上一个节点
	}
}
int getListNodeSize(List* list)
{
	return list->size;
}

void emptyList(List* list)
{
	if (0 == list->size)
	{
		printf("链表为空!\n");
		return;
	}
}

void clear(List* list)
{
	emptyList(list);
	Node* clear_Node = list->head->next;		//定义一个指针指向链表第一个节点(非头结点)
	while (clear_Node != list->head)
	{
		Node* temp = clear_Node->next;
		free(clear_Node);
		clear_Node = temp;
		--list->size;							//每删除一个节点size-1
	}
	list->head->front = list->head->next = list->head;	//回到链表初始状态
}

Node* find_List(List* list, int id)
{
	emptyList(list);
	Node* find_Node = list->head->next;		//定义一个指针指向链表第一个节点(非头结点)
	while (find_Node != list->head && find_Node->data != id)
	{
		find_Node = find_Node->next;
	}
	//可以打印下找到的节点的属性
	//...
	return find_Node;
}

void insert(List* list, Node* pos, int data)
{
	emptyList(list);
}

void erase(List* list, Node* pos)
{
	emptyList(list);
}