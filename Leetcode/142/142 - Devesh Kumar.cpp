/* Problem no. 142 Linked list cycle 2
	Problem link . https://leetcode.com/problems/linked-list-cycle-ii/
	
	Submitted by - Devesh Kumar

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> v;
        for(;head!=NULL;head=head->next)
        {
            if(v.find(head)!=v.end())
            {
            	return head;
			}
			else
			{
				v.insert(head);
			}
        }
        return head;
    }
};
