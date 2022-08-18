/*  Problem Number - 21. Merge two sorted lists
    Problem URL - https://leetcode.com/problems/reverse-linked-list/

    Submitted by Devesh Kumar 
	LinkedIn- linkedin.com/in/devesh-k-110862113/
	Time complexity - O(n)
	Space complexity - O(n)




 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
struct ListNode{
	int val;
	listNode* next=NULL;
};
ListNode *start1=NULL,*start2=NULL,*end=NULL;
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* end=NULL,*head=NULL;
        if(list1==NULL)
        {
            return list2;
        }
        if(list2==NULL)
        {
            return list1;
        }
        for(;list1!=NULL&&list2!=NULL;)
        {
            if((list1->val)<=(list2->val))
            {
                if(end!=NULL)
                {
                    end->next=list1;
                    end=end->next;
                }
                else
                {
                    end=list1;
                    head=list1;
                }
                list1=list1->next;
            }
            else
            {
                if(end!=NULL)
                {
                    end->next=list2;
                    end=end->next;
                }
                else
                {
                    end=list2;
                    head=list2;
                }
                list2=list2->next;
            }
        }
        if(list1==NULL)
        {
            end->next=list2;
        }
        if(list2==NULL)
        {
            end->next=list1;
        }
        return head;
    }
};
void add_node(int val,ListNode* end,ListNode* start)
{
	ListNode *new_node=new ListNode;
	new_node->val=val;
	if(start!=NULL)
		end->next=new_node;
	if(start==NULL)
	{
		start=end=new_node;
	}
}
int main()
{
	int n,num;
	cout<<"Enter number of elements in list 1";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		add_node(num,end,start1);
	}
	cout<<"\nEnter number of elements in list 2";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		add_node(num,end,start2);
	}
	Solution s;
	s.mergeTwoLists(start1,start2);
}
