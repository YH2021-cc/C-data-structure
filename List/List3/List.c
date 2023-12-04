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
	Node* tail = list->head->front;			//����һ���ڵ�ָ��ָ���β�ڵ�(���Ϊͷ�ڵ�)
	tail->next = newNode;					//�þ�β�ڵ�(���Ϊͷ�ڵ�)��nextָ��ָ���½ڵ�
	newNode->front = tail;					//���½ڵ��frontָ��ָ���β�ڵ�(���Ϊͷ�ڵ�)
	newNode->next = list->head;				//���½ڵ��nextָ��ָ��ͷ�ڵ�
	list->head->front = newNode;			//��ͷ�ڵ��frontָ��ָ����β�ڵ�(�µĽڵ�)
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
	Node* newNode = createNode(data);
	assert(newNode);
	Node* tPtr = list->head->next;			//����һ���ڵ�ָ��ָ���½ڵ�֮ǰ�Ľڵ�(���Ϊͷ�ڵ�)
	tPtr->front = newNode;					//���½ڵ�֮ǰ�Ľڵ��frontָ��ָ���½ڵ�
	newNode->front = list->head;			//���½ڵ��frontָ��ָ��ͷ�ڵ�
	newNode->next = tPtr;					//���½ڵ��nextָ��ָ���½ڵ�֮ǰ�Ľڵ�
	list->head->next = newNode;				//ͷ�ڵ��nextָ��ָ���½ڵ�
	++list->size;
}

void pop_Front(List* list)
{
	emptyList(list);
	Node* pop_Ptr = list->head->next;		//����һ���ڵ�ָ��ָ��Ҫɾ��(ͷ�ڵ��nextָ��)�Ľڵ�
	list->head->next = pop_Ptr->next;		//��ͷ����nextָ��Ҫɾ���Ľڵ����һ���ڵ�
	pop_Ptr->next->front = list->head;		//��Ҫɾ���Ľڵ����һ���ڵ��frontָ��ͷ�ڵ�
	free(pop_Ptr);
	pop_Ptr = NULL;
	--list->size;
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
	Node* clear_Node = list->head->next;				//����һ��ָ��ָ�������һ���ڵ�(��ͷ���)
	while (clear_Node != list->head)
	{
		Node* temp = clear_Node->next;
		free(clear_Node);
		clear_Node = temp;
		--list->size;									//ÿɾ��һ���ڵ�size-1
	}
	list->head->front = list->head->next = list->head;	//�ص������ʼ״̬
}

Node* find_List(List* list)
{
	emptyList(list);
	int erase_Id = 0;
	scanf("%d", &erase_Id);
	Node* find_Node = list->head->next;		//����һ��ָ��ָ�������һ���ڵ�(��ͷ���)
	while (find_Node != list->head && find_Node->data != erase_Id)
	{
		find_Node = find_Node->next;
	}
	//���Դ�ӡ���ҵ��Ľڵ������
	//...
	if (find_Node == list->head)
	{
		printf("���ݲ�����!\n");
		return NULL;
	}
	return find_Node;
}

void insert(List* list, ListData data)				//�ھɽڵ��������½ڵ�
{
	emptyList(list);
	printf("������Ҫ���������Ľڵ�id: ");
	Node* insert_Node = find_List(list);			//���վɽڵ�
	if (insert_Node == NULL)return;					//������ݲ����ھͽ���
	Node* newNode = createNode(data);				//�����½ڵ�
	newNode->front = insert_Node;					//���½ڵ��frontָ��ɽڵ�
	newNode->next = insert_Node->next;				//���½ڵ��nextָ��ɽڵ����Ľڵ�
	insert_Node->next->front = newNode;				//�þɽڵ����Ľڵ��frontָ���½ڵ�
	insert_Node->next = newNode;					//�þɽڵ��nextָ���½ڵ�
	++list->size;
}

void erase(List* list)
{
	emptyList(list);
	printf("������Ҫɾ���Ľڵ�id: ");
	Node* erase_Node = find_List(list);					//����Ҫɾ���Ľڵ�
	if (erase_Node == NULL)return;						//������ݲ����ھͽ���
	erase_Node->front->next = erase_Node->next;			//��Ҫɾ���Ľڵ����ڵ��nextָ��Ҫɾ���Ľڵ���ҽڵ�
	erase_Node->next->front = erase_Node->front;		//��Ҫɾ���Ľڵ���ҽڵ��frontָ��Ҫɾ���Ľڵ����ڵ�
	free(erase_Node);
	erase_Node = NULL;
	--list->size;
}