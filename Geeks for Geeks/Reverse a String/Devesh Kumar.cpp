/*
	Problem Link - https://practice.geeksforgeeks.org/problems/reverse-a-string
	
	Submitted By - Devesh Kumar
	
	Time complexity - O(n)
	Space Complexity - O(n)
*/



//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> ans;
        int max=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>=max)
            {
                ans.push_back(a[i]);
                max=a[i];
            }
        }
        int len=ans.size();
        for(int i=0;i<len/2;i++)
        {
            int temp=ans[i];
            ans[i]=ans[len-i-1];
            ans[len-i-1]=temp;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends
