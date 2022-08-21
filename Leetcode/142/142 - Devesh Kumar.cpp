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
        vector<vector<ListNode*>> v(200001);
        for(;head!=NULL;head=head->next)
        {
            int num=(head->val<0)?head->val+10000:head->val;
            for(int i=0;i<v[num].size();i++)
            {
                if(v[num][i]==head)
                    return v[num][i];
            }
            v[num].push_back(head);

        }
        return head;
    }
};
