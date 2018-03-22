class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preresult(0);//最后返回的是链表头，所以头部的要始终能访问到 
        ListNode *pre=&preresult;//去动指针 
        int extra=0;
        while(l1||l2||extra){
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+extra; //三目运算简化逻辑 
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