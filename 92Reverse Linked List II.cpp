#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;    
	ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode * first = new ListNode(0), *t_head, *first_reverse, *node;
		first->next = head;
		t_head = first;
		for (int i = 0; i<m - 1; i++)
			t_head = t_head->next;
		first_reverse = t_head->next;
		node = t_head->next;
		for (int i = m; i <= n; i++)
		{
			ListNode * temp = node->next;
			node->next = t_head->next;
			t_head->next = node;
			node = temp;
		}
		first_reverse->next = node;
		return first->next;
	}
};

void print_node(ListNode *head){


	if (head) {
		while (head) {
			cout << head->val << endl;
			head = head->next;
		}
	}
	else {
		cout << "List is NULL" << endl;
	}

}
int main() {
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode *head;

	head = &a;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = NULL;

	print_node(head);
	Solution s;
	head=s.reverseBetween(head,1,4);
	print_node(head);

	cin.get();
	return 0;
	

	

}