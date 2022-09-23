For more such solution follow GITHUB - https://github.com/azrael18102001/Solutions
/*
	Question Title - Nth node from end of linked list
	Question Link - https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

	Submitted by - Devesh Kumar

	Time Complexity - O(N)
	Space Complexity - O(1)
*/

//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
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


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n)
{
       int count=0;
       Node* before=head,*after=head;
       while(count<n-1)
       {
           after=after->next;
           count++;
           if(after==NULL)
           return -1;
       }
       while(after->next!=NULL)
       {
           after=after->next;
           before=before->next;
       }
       return before->data;
}


