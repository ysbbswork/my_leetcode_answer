class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preresult(0);//��󷵻ص�������ͷ������ͷ����Ҫʼ���ܷ��ʵ� 
        ListNode *pre=&preresult;//ȥ��ָ�� 
        int extra=0;
        while(l1||l2||extra){
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+extra; //��Ŀ������߼� 
            extra=sum/10;
            int value=sum%10;
            ListNode *nextnode = new ListNode(0);
            nextnode->val=value;
            pre->next=nextnode; 
            pre=pre->next;
            l1=(l1?l1->next:NULL);
            l2=(l2?l2->next:NULL);
        
    }
        return preresult.next;
    }
};