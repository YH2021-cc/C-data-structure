#include "TwoList.h"

//�����ڵ�
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	assert(newNode);//�������ʧ�ܷ��ؿ�
	newNode->data = data;
	newNode->front = newNode->next = NULL;
	return newNode;
}

//����˫������
struct List* createList()
{
	//�����ڴ�
	struct List* list = (struct List*)malloc(sizeof(struct List));
	//��ʼ������
	assert(list);
	list->firstNode = list->lastNode = NULL;
	list->size = 0;
	return list;
}

/*Ҫ���ĸ��������,���������*/
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
	list->firstNode = newNode;//�ı��ͷλ��
	list->size++;
}

//��β������
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
	list->lastNode = newNode;//�ı��βλ��
	list->size++;
}

//��ӡ����
//ǰָ���ӡ(˳���ӡ)
void printListFront(struct List* list)
{
	if (list->size == 0)
		printf("����Ϊ��,�޷���ӡ!\n");
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

//��ָ���ӡ(�����ӡ)
void printListNext(struct List* list)
{
	if (list->size == 0)
		printf("����Ϊ��,�޷���ӡ!\n");
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

//ָ��λ�ò���
/*Ҫ���������,Ҫ���������,Ҫ�����λ��*/
void findNodeinsert(struct List* list, int data, int posData)
{
	if (list->size == 0)
	{
		printf("����Ϊ��,�޷�����!\n");
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
			printf("δ�ҵ�ָ��λ��,�޷�����!\n");
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