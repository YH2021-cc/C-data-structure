#include "List1.h"

ListNode* CreateNode(Data x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void PushBack(ListNode** list, Data x)
{
	//创建新节点
	ListNode* newNode = CreateNode(x);

	//如果链表为空
	if (*list == NULL)		//因为形参list是ListNode*而实参list也是ListNode*,同类型是值传递不会改变实参值,
	{						//所以需要传递实参的地址,对于指针变量而言就是二级指针
		*list = newNode;	//将新节点作为链表的第一个节点(需要用二级指针来保存newnode的地址,直接指向不行)
	}
	else
	{
		//寻找尾节点
		ListNode* tail = *list;			//定义一个节点指针指向链表(*list表示链表中的节点,list表示链表的地址)
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//连接新节点
		tail->next = newNode;
	}
}

void PushFront(ListNode** list, Data x)
{
	//创建新节点
	ListNode* newNode = CreateNode(x);

	//新节点的next指向*list(第一次插入时他为null,所以第一次插入的节点的next指向null)
	//所以第一次插入的节点就成为链表的头节点
	newNode->next = *list;
	//让*list这个空指针指向新节点,当下次插入时,新新节点的next就会指向第一次插入的节点
	//也就是说新新节点会指向第一次插入的节点并取代它成为新的头节点
	*list = newNode;
	//每次插入的新节点都会成为链表的头节点
}

void PopBack(ListNode** list)
{
	assert(*list);
	ListNode* tailLeft = NULL;
	ListNode* tail = *list;
	while (tail->next != NULL)
	{
		tailLeft = tail;
		tail = tail->next;
	}
	if (tailLeft == NULL)
		return;
	tailLeft->next = tail->next;
	free(tail);
	tail = NULL;
}

void PopFront(ListNode** list)
{
	assert(*list);
	ListNode* front = *list;	//因为*list是指向链表的第一个节点所以front也指向第一个节点
	*list = front->next;		//让*list指向第二节点,使其成为第一节点被删除后的第一节点
	free(front);			//删除第一节点
	front = NULL;
}

void Erase(ListNode** list, Data x)
{
	assert(*list);
	ListNode* popNodeLeft = NULL;
	ListNode* popNode = *list;
	while (popNode->data != x)
	{
		popNodeLeft = popNode;
		popNode = popNode->next;
	}
	if (popNodeLeft == NULL)		//此时说明没有找到要删除的节点
		return;
	popNodeLeft->next = popNode->next;
	free(popNode);
	popNode = NULL;
}

void PrintList(ListNode* list)
{
	assert(list);
	ListNode* pList = list;
	while (pList)
	{
		printf("%d ", pList->data);
		pList = pList->next;
	}
}

bool Empty(ListNode** list)
{
	return *list == NULL;
}

int Size(ListNode** list)
{
	if (Empty(list))
	{
		return 0;
	}
	int nodeCount = 0;
	ListNode* p = *list;
	while (p)
	{
		nodeCount++;
		p = p->next;
	}
	return nodeCount;
}