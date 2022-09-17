For more such solution follow GITHUB
/*
	Question Title - Reverse a Linked List in groups of given size.
	Question Link - https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

	Submitted by - Devesh Kumar

	Time Complexity - O(n)
	Space Complexity - O(1)
*/

for(;current_node!=NULL;)
        {
             if(c==0)
             {
                 temp_head=current_node;
                if(last_temp_head==NULL)
                last_temp_head=current_node;
             }
             current_node->next=previous_node;
             previous_node=current_node;
             current_node=next_node;
            if(next_node!=NULL)
             next_node=next_node->next;
             c++;
            if(c==k||current_node==NULL)
               {
                   if(returning_head==NULL)
                   {
                       returning_head=previous_node;
                   }
                   else
                   {
                       last_temp_head->next=previous_node;
                       last_temp_head=temp_head;
                   }
                   c=0;
                   previous_node=NULL;
               }
        }
