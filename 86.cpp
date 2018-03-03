class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode biger(0);
		ListNode *pbiger = &biger;
		ListNode smaller(0);
		ListNode *psmaller = &smaller;
		while (head) {
			if (head->val < x) {
				psmaller->next = head;
				psmaller = psmaller->next;
			}
			else {
				pbiger->next = head;
				pbiger = pbiger->next;
			}
			
			head = head->next;

			}
		psmaller->next = biger.next;
		pbiger->next = NULL;
		return smaller.next;
		}
};
