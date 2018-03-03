//Í·²å·¨ÄæÖÃÁ´±í

#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;    
	ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode newhead(0);
		newhead.next = NULL;
		while (head) {
			listnode *tempnext = head->next;
			head->next = newhead.next;
			newhead->next = head;
			head = head->next;

		}

		return newhead.next ;
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
	head=s.reverseList(head);
	print_node(head);

	cin.get();
	return 0;
	

	

}