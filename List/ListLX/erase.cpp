//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回新的头节点
#include<stdio.h>
#include<malloc.h>
struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* front = NULL;		//指向和val值相等的节点的上一个节点
	struct ListNode* cur = head;		//当前节点
	while (cur)
	{
		if (cur->val == val)
		{
			if (cur == head)           //如果第一个节点的val值和val值相等就将头节点指向下一个节点释放原来的头节点
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