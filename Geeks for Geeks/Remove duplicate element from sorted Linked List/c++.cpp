For more such solution follow GITHUB
/*
	Question Title - Remove duplicate element from sorted Linked List
	Question Link - https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

	Submitted by - Devesh Kumar

	Time Complexity - O(n)
	Space Complexity - O(1)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    Node* t=head,*last_node=head;
    for(;t!=NULL;t=t->next)
    {
        if(t->data!=last_node->data)
        {
            last_node->next=t;
            last_node=t;
        }
    }
    last_node->next=NULL;
    return head;
 // your code goes here
}
