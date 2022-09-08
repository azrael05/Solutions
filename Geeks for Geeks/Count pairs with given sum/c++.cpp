/*
	Problem Link - https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
	
	Submitted By- Devesh Kumar
	
	Time complexity-O(n)
	Space Complexity-O(n)
*/	
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) 
	{
		int total_pairs=0;
		vector<int> frequency_of_number(1000000,0);
		for(int position=0;position<n;position++)
		{
	    	if(k-arr[position]-1>=0 && k-arr[position]-1<1000000)	//check if value is overflowing
	    		total_pairs+=frequency_of_number[k-arr[position]-1];	//add frequency of required number
	    	frequency_of_number[arr[i]-1]++;	//add frequency	
		}
		return total_pairs;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends
