//����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬�������µ�ͷ�ڵ�
#include<stdio.h>
#include<malloc.h>
struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* front = NULL;		//ָ���valֵ��ȵĽڵ����һ���ڵ�
	struct ListNode* cur = head;		//��ǰ�ڵ�
	while (cur)
	{
		if (cur->val == val)
		{
			if (cur == head)           //�����һ���ڵ��valֵ��valֵ��Ⱦͽ�ͷ�ڵ�ָ����һ���ڵ��ͷ�ԭ����ͷ�ڵ�
			{
				head = head->next;
				free(cur);
				cur = head;
			}
			else
			{
				front->next = cur->next;
				free(cur);
				cur = front->next;
			}
		}
		else
		{
			front = cur;
			cur = cur->next;
		}
	}
	return head;
}