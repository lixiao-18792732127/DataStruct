#include<iostream>
using namespace std;
#include<algorithm>

struct Node
{
	int _value;
	Node* _next;
};

void Insert(Node *&head, int value)
{
	Node* node = new Node;
	node->_value = value;
	node->_next = head;
	head = node;
}

//判断链表是否带环
Node* IsCircle(Node* head)
{
	Node *fast = NULL;
	Node *slow = NULL;
	while (fast != NULL && fast->_next != NULL)
	{
		fast = fast->_next->_next;
		slow = slow->_next;
		if (fast = slow)
		{
			return slow;
		}
	}
	return NULL;
}

Node* FindCircleEnterance(Node* head, Node *pos)
{
	while (head != pos)
	{
		head = head->_next;
		pos = pos->_next;
	}
	return head;
}

Node* FindFirstCross(Node* head1, Node* head2)
{
	Node* pos1 = IsCircle(head1);
	Node* pos2 = IsCircle(head2);
	if (pos1&&pos2 || !pos1&&pos2)
	{
		return NULL;
	}
	Node *nd1, *nd2;
	if (!pos1&&!pos2)
	{
		int len1, len2;
		len1 = len2 = 0;
		nd1 = head1;
		while (nd1)
		{
			len1++;
			nd1 = nd1->_next;
		}
		nd2 = head2;
		while (nd2)
		{
			len2++;
			nd2 = nd2->_next;
		}
		int dif;
		nd1 = head1;
		nd2 = head2;
		if (len1 >= len2)
		{
			dif = len1 - len2;
			while (dif--)
			{
				nd1 = nd1->_next;
			}
		}
		else
		{
			dif = len2 - len1;
			while (dif--)
			{
				nd2 = nd2->_next;
			}
		}
		while (nd1&&nd2)
		{
			if (nd1 == nd2)
			{
				return nd1;
			}
			nd1 = nd1->_next;
			nd2 = nd2->_next;
		}
		return NULL;
	}

	if (pos1&&pos2)
	{
		Node*tmp = pos1;
		do
		{
			if (pos1 == pos2 || pos1->_next == pos2)
			{
				break;
			}
			pos1 = pos1->_next->_next;
			tmp = tmp->_next;
		} while (pos1 != tmp);
		if (pos1 != pos2&&pos1->_next != pos2)
		{
			return NULL;
		}
		int len1, len2;
		len1 = len2 = 0;
		Node *nd1, *nd2;
		nd1 = head1;
		while (nd1 != pos1)
		{
			len1++;
			nd1 = nd1->_next;
		}
		nd2 = head2;
		while (nd2 != pos2)
		{
			len2++;
			nd2 = nd2->_next;
		}
		int dif;
		nd1 = head1;
		nd2 = head2;
		if (len1 > -len2)
		{
			dif = len1 - len2;
			while (dif--)
			{
				nd1 = nd1->_next;
			}
		}
		else
		{
			dif = len2 - len1;
			while (dif--)
			{
				nd2 = nd2->_next;
			}
		}
		while (nd1 == nd2)
		{
			if (nd1 == nd2)
			{
				return nd1;
			}
			nd1 = nd1->_next;
			nd2 = nd2->_next;
		}
		return pos1;
	}
}