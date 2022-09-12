/*
	Problem No- 234. Palindrome Linked List
	Problem Link- https://leetcode.com/problems/palindrome-linked-list/
	
	Submitted by - Devesh Kumar
	
	Time complexity - O(n)
	Space Complexity - O(1)
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
        {
            return true;
        }
        ListNode* mid=head,*start=head,*prev_node=NULL,*next_node=head->next;
        int count=0;
        while(1)
        {
            if(mid->next==NULL)
            {
                count=1;
                break;
            }
            if(mid->next->next==NULL)
            {
                start->next=prev_node;
                break;
            }
            mid=mid->next->next;
            start->next=prev_node;
            prev_node=start;
            start=next_node;
            next_node=next_node->next;
        }
        if(count==1)
        {
            while(prev_node!=NULL)
            {
                if(prev_node->val!=next_node->val)
                    return false;
                prev_node=prev_node->next;
                next_node=next_node->next;
            }
            return true;
        }
        else
        {
            while(start!=NULL)
            {
                if(start->val!=next_node->val)
                    return false;
                start=start->next;
                next_node=next_node->next;
            }
            
            return true;
        }
        return false;
    }
};
