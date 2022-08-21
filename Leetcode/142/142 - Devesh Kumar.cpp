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
        int index=0;
        for(;head!=NULL;head=head->next)
        {
            int num=(head->val<0)?head->val+10000:head->val;
            for(int i=0;i<v[num].size();i++)
            {
                if(v[num][i]->next==head)
                    return v[num][i]->next;
            }
            ListNode* new_node=new ListNode;
            new_node->val=index++;
            new_node->next=head;
            v[num].push_back(new_node);

        }
        return head;
    }
};
