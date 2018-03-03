/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

#include <map>
#include <vector>

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		std::map<RandomListNode *, int> nodemap;
		std::vector<RandomListNode *> newnode;
		RandomListNode *ptr = head;
		int i = 0;
		while (ptr) {
			newnode.push_back(new RandomListNode(ptr->label));
			nodemap[ptr] = i;
			i++;
			ptr = ptr->next;

		}

		ptr = head;
		newnode.push_back(0);
		i = 0;
		while (ptr) {
			newnode[i]->next=newnode[i + 1];
			if (ptr->random) {
				int id = nodemap[ptr->random];
				newnode[i]->random = newnode[id];
			}
			i++;
			ptr = ptr->next;
		}
		return newnode[0];
	}
};