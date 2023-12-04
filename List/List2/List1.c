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
	//�����½ڵ�
	ListNode* newNode = CreateNode(x);

	//�������Ϊ��
	if (*list == NULL)		//��Ϊ�β�list��ListNode*��ʵ��listҲ��ListNode*,ͬ������ֵ���ݲ���ı�ʵ��ֵ,
	{						//������Ҫ����ʵ�εĵ�ַ,����ָ��������Ծ��Ƕ���ָ��
		*list = newNode;	//���½ڵ���Ϊ����ĵ�һ���ڵ�(��Ҫ�ö���ָ��������newnode�ĵ�ַ,ֱ��ָ����)
	}
	else
	{
		//Ѱ��β�ڵ�
		ListNode* tail = *list;			//����һ���ڵ�ָ��ָ������(*list��ʾ�����еĽڵ�,list��ʾ����ĵ�ַ)
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//�����½ڵ�
		tail->next = newNode;
	}
}

void PushFront(ListNode** list, Data x)
{
	//�����½ڵ�
	ListNode* newNode = CreateNode(x);

	//�½ڵ��nextָ��*list(��һ�β���ʱ��Ϊnull,���Ե�һ�β���Ľڵ��nextָ��null)
	//���Ե�һ�β���Ľڵ�ͳ�Ϊ�����ͷ�ڵ�
	newNode->next = *list;
	//��*list�����ָ��ָ���½ڵ�,���´β���ʱ,���½ڵ��next�ͻ�ָ���һ�β���Ľڵ�
	//Ҳ����˵���½ڵ��ָ���һ�β���Ľڵ㲢ȡ������Ϊ�µ�ͷ�ڵ�
	*list = newNode;
	//ÿ�β�����½ڵ㶼���Ϊ�����ͷ�ڵ�
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
	ListNode* front = *list;	//��Ϊ*list��ָ������ĵ�һ���ڵ�����frontҲָ���һ���ڵ�
	*list = front->next;		//��*listָ��ڶ��ڵ�,ʹ���Ϊ��һ�ڵ㱻ɾ����ĵ�һ�ڵ�
	free(front);			//ɾ����һ�ڵ�
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
	if (popNodeLeft == NULL)		//��ʱ˵��û���ҵ�Ҫɾ���Ľڵ�
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