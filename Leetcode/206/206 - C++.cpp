/*  Problem Number - 206. Reverse a Linked List
    Problem URL - https://leetcode.com/problems/reverse-linked-list/

    Submitted by Devesh Kumar 
	LinkedIn- linkedin.com/in/devesh-k-110862113/
	Time complexity - O(n)
	Space complexity - O(1)




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
    	/* If linked list is empty return head pointer*/
        if(head==NULL)
        {
            return head;
        }
        ListNode *back=head,*front=head->next,*temp;
        head->next=NULL;  //Set the next of head node as NULL
        for(;front!=NULL;)
        {
            temp=front->next;     //store the next node in temporary pointer
            front->next=back;		  // set the value of next in current node to point to previous node 
            back=front;			  // make current node to previous node for next iteration
            front=temp;			  // shift next node to current node for next iteration
        }
            
        return back;       //return back which would be pointing at the orignally last Node
    }
};
