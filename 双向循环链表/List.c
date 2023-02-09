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
	Node* tail = list->head->front;			//����һ���ڵ�ָ��ָ��β�ڵ�(���Ϊͷ�ڵ�)
	tail->next = newNode;					//��β�ڵ�(���Ϊͷ�ڵ�)��nextָ��ָ���½ڵ�
	newNode->front = tail;					//���½ڵ��frontָ��ָ��ǰһ���ڵ�(���Ϊͷ�ڵ�)
	newNode->next = list->head;				//���½ڵ��nextָ��ָ��ͷ�ڵ�
	list->head->front = newNode;			//��ͷ�ڵ��frontָ��ָ��β�ڵ�(�µĽڵ�)
	++list->size;
}

void pop_Back(List* list)
{
	emptyList(list);
	Node* back_Node = list->head->front;		//����һ���ڵ�ָ��ָ�������β�ڵ�
	back_Node->front->next = list->head;		//ʹβ�ڵ��ǰһ���ڵ��nextָ��ָ��ͷ�ڵ�
	list->head->front = back_Node->front;		//ͷ�ڵ��frontָ���µ�β�ڵ�
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

void print_ZList(List* list)					//�����ӡ
{
	//�ж������Ƿ�Ϊ��
	emptyList(list);

	//�����������ֹ�����ǲ�ָ��ͷ�ڵ�
	Node* print = list->head->next;		//����һ���ڵ�ָ��ָ�������еĵ�һ���ڵ�(��ͷ���)
	while (print != list->head)
	{
		printf("%d\t\n", print->data);	//��ӡ����
		print = print->next;			//ָ����һ���ڵ�
	}
}

void print_NList(List* list)			//�����ӡ
{
	//�ж������Ƿ�Ϊ��
	emptyList(list);
	//�����������ֹ�����ǲ�ָ��ͷ�ڵ�
	Node* print = list->head->front;		//����һ���ڵ�ָ��ָ��β�ڵ�
	while (print != list->head)
	{
		printf("%d\t\n", print->data);		//��ӡ����
		print = print->front;				//ָ����һ���ڵ�
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
		printf("����Ϊ��!\n");
		return;
	}
}

void clear(List* list)
{
	emptyList(list);
	Node* clear_Node = list->head->next;		//����һ��ָ��ָ�������һ���ڵ�(��ͷ���)
	while (clear_Node != list->head)
	{
		Node* temp = clear_Node->next;
		free(clear_Node);
		clear_Node = temp;
		--list->size;							//ÿɾ��һ���ڵ�size-1
	}
	list->head->front = list->head->next = list->head;	//�ص������ʼ״̬
}

Node* find_List(List* list, int id)
{
	emptyList(list);
	Node* find_Node = list->head->next;		//����һ��ָ��ָ�������һ���ڵ�(��ͷ���)
	while (find_Node != list->head && find_Node->data != id)
	{
		find_Node = find_Node->next;
	}
	//���Դ�ӡ���ҵ��Ľڵ������
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