/*
	Problem - Max Contigious Subarray
	Problem Link -	https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1 

	Submitted by - Devesh Kumar
	
	Time Complexity - O(n)
	Space Complexity - O(1)
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int a[], int n){
        
        // Your code here
        long max_sum=INT_MIN,sum=0,max=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum=sum+a[i];
            if(sum>=max_sum)
            {
                max_sum=sum;
            }
            if(a[i]>max)
            {
                max=a[i];
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        if(max_sum==0)
        {
            max_sum=max;
        }
        return max_sum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends
