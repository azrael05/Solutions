/* 
	Question Title - Check if Linked List is Palindrome	
	Question Link - https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
	
	Submitted by - Devesh Kumar
	
	Time Complexity - O(n)
	Space Complexity - O(1)
*/

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head==NULL)
        {
            return true;
        }
        Node* middle_node=head,*start=head,*previous_node=NULL,*next_node=head->next;
        int number_of_nodes=0;
        while(1)
        {
            if(middle_node->next==NULL)
            {
                number_of_nodes=1;
                break;
            }
            if(middle_node->next->next==NULL)
            {
                start->next=previous_node;
                break;
            }
            middle_node=middle_node->next->next;
            start->next=previous_node;
            previous_node=start;
            start=next_node;
            next_node=next_node->next;
        }
        if(number_of_nodes==1)
        {
            while(previous_node!=NULL)
            {
                if(previous_node->data!=next_node->data)
                    return false;
                previous_node=previous_node->next;
                next_node=next_node->next;
            }
            return true;
        }
        else
        {
            while(start!=NULL)
            {
                if(start->data!=next_node->data)
                    return false;
                start=start->next;
                next_node=next_node->next;
            }
            
            return true;
        }
        return false;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
