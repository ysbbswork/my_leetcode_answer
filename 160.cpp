/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int get_list_len(ListNode *list) {
	int len = 0;
	while (list) {
		len++;
		list = list->next;
	}
    return len;
}

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int Alen = get_list_len(headA);
		int Blen = get_list_len(headB);
		int same = Blen - Alen;
		if (same>0) {
			 while (same) {
				 headB = headB->next;
				 same--;
			 }
		}
		else {
			while (same) {
				headA = headA->next;
				same++;
			}
		}
		while (headA&&headB) {
			if (headA == headB) {
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;

	}
};
