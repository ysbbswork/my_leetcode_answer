/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include<map>
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return NULL;
        RandomListNode *purehead=head;
        std::map<RandomListNode * , int> nodemap1;
        std::map<int , RandomListNode *> nodemap2;
        RandomListNode newhead(0);
        RandomListNode * pnewhead=&newhead;
        int num =1;
        nodemap1[NULL]=0;
        nodemap2[0]=NULL;
        while(head){
            RandomListNode *node = new RandomListNode(0);
            node->label=head->label;
            nodemap1[head]=num;
            nodemap2[num]=node;
            pnewhead->next=node;
            pnewhead=pnewhead->next;
            head=head->next;   
            num++;
        }
        pnewhead->next=NULL;
        RandomListNode *pnew=newhead.next;
        while(purehead&&pnew){
            pnew->random=nodemap2[nodemap1[purehead->random]];
            purehead=purehead->next;
            pnew=pnew->next;
            
        }
        return newhead.next;
    }
};