// Problem Number - 206. Reverse a Linked List
// Problem URL - https://leetcode.com/problems/reverse-linked-list/

/* Submitted by Devesh Kumar 
LinkedIn- linkedin.com/in/devesh-k-110862113/

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
        {
            return head;
        }
        ListNode *b=head,*f=head->next,*temp;
        head->next=NULL;
        for(;f!=NULL;)
        {
            temp=f->next;
            f->next=b;
            b=f;
            f=temp;
        }
            
        return b;
    }
};
