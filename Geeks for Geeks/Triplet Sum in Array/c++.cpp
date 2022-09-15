/* 
	Question Title - Triplet Sum in Array
	Question Link - https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
	
	Submitted by - Devesh Kumar
	
	Time Complexity - O(n2)
	Space Complexity - O(n)
*/
	


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        vector<int> frequency_of_numbers(100001,0);
        for(int position=0; position<n; position++)
        {
            frequency_of_numbers[A[position]]++;
        }
        for(int position_of_first_number=0 ; position_of_first_number<n ; position_of_first_number++)
        {
            for(int position_of_second_number=position_of_first_number+1 ; position_of_second_number<n ; position_of_second_number++)
            {
                if(A[position_of_first_number] + A[position_of_second_number]>X)
                {
                    continue;
                }
                if(check_if_triplet_exists(X, A[position_of_first_number], A[position_of_second_number], frequency_of_numbers))
                {
                    // cout<<A[position_of_first_number]<<" "<<A[position_of_second_number];
                    return true;
                }
            }
        }
        return false;
    }
    bool check_if_triplet_exists(int target_number,int first_number,int second_number,vector<int> &frequency_of_numbers)
    {
        int number_of_used_third_numbers = 0, third_number=target_number-first_number-second_number;
        if(third_number == first_number)
        {
            number_of_used_third_numbers++;
        }
        if(third_number == second_number)
        {
            number_of_used_third_numbers++;
        }
        
        if(frequency_of_numbers[third_number] - number_of_used_third_numbers > 0)
        {
            // cout<<first_number<<" "<<second_number<<" "<<third_number;
            return true;
        }
        else
        {
            return false;
        }
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends
