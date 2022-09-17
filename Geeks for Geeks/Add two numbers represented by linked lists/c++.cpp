For more such solution follow GITHUB - https://github.com/azrael18102001/Solutions
/*
	Question Title - Add two numbers represented by linked lists
	Question Link - https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

	Submitted by - Devesh Kumar

	Time Complexity - O(N+M)
	Space Complexity - O(max(N,M))
*/

//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node *previous_node=NULL,*current_node=first,*next_node=first->next;
        while(current_node!=NULL)
        {
            current_node->next=previous_node;
            previous_node=current_node;
            current_node=next_node;
            if(next_node!=NULL)
            next_node=next_node->next;
        }
        first=previous_node;
        previous_node=NULL,current_node=second,next_node=second->next;
        while(current_node!=NULL)
        {
            current_node->next=previous_node;
            previous_node=current_node;
            current_node=next_node;
            if(next_node!=NULL)
            next_node=next_node->next;
        }
        second=previous_node;
        Node* new_linked_list=NULL,*last;
        int carry=0;
        while(first!=NULL || second!=NULL)
        {
            int v1=first==NULL?0:first->data;
            int v2=second==NULL?0:second->data;
            int temp=v1+v2+carry;
            carry=temp/10;
            temp=temp%10;
            if(new_linked_list==NULL)
            {
                new_linked_list=new Node(temp);
                last=new_linked_list;
            }
            else
            {
                last->next=new Node(temp);
                last=last->next;
            }
            if(first!=NULL)
            {
                first=first->next;
            }
            if(second!=NULL)
            {
                second=second->next;
            }
        }
        if(carry!=0)
        {
            last->next = new Node(carry);
        }
        previous_node=NULL,current_node=new_linked_list,next_node=new_linked_list->next;
        while(current_node!=NULL)
        {
            current_node->next=previous_node;
            previous_node=current_node;
            current_node=next_node;
            if(next_node!=NULL)
            next_node=next_node->next;
        }
        new_linked_list=previous_node;
    return new_linked_list;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
