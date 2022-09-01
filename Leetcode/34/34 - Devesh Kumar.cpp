/*
Problem Number 34 - Swap Nodes in Pairs
Problem Link - https://leetcode.com/problems/swap-nodes-in-pairs/ 

Submitted By - Devesh Kumar

Time complexity - O(n)
Space Complexity O(1) 
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        if(head->next!=NULL)
        {
            ListNode* ans=head->next;
            ListNode* one=head,*two=NULL;
            for(;one!=NULL;one=one->next)
            {
                    if(one->next!=NULL)
                    {
                        if(two!=NULL)
                            two->next=one->next;
                        two=one->next;
                        one->next=two->next;
                        two->next=one;
                        two=one;
                    }
                    else
                    {
                        break;
                    }
                
            }
            return ans;
        }
        return head;
    }
};
