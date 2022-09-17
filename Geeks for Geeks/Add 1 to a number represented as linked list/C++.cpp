For more such solution follow GITHUB - https://github.com/azrael18102001/Solutions
/*
	Question Title - Add 1 to a number represented as linked list
	Question Link - https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

	Submitted by - Devesh Kumar

	Time Complexity - O(N+M)
	Space Complexity - O(max(N,M))
*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node* previous_node=NULL,*current_node=head,*next_node=head->next;
        while(current_node!=NULL)
        {
            current_node->next=previous_node;
            previous_node=current_node;
            current_node=next_node;
            if(next_node!=NULL)
            {
                next_node=next_node->next;
            }
        }
        head=previous_node;
        int carry=1;
        Node* thead=head;
        while(thead!=NULL)
        {
            int temp=thead->data+carry;
            carry=temp/10;
            temp=temp%10;
            thead->data=temp;
            if(carry==0)
            {
                break;
            }
            thead=thead->next;
        }
        previous_node=NULL,current_node=head,next_node=head->next;
        while(current_node!=NULL)
        {
            current_node->next=previous_node;
            previous_node=current_node;
            current_node=next_node;
            if(next_node!=NULL)
            {
                next_node=next_node->next;
            }
        }
        head=previous_node;
        if(carry!=0)
        {
          thead=new Node(carry);
          thead->next=head;
        }
        else
        {
            thead=head;
        }
        return thead;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends
