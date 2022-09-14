/* 
	Problem no. Common elements
	Problem Link - https://practice.geeksforgeeks.org/problems/common-elements1132/1
	
	Submitted by - Devesh Kumar
	
	Time complexity - O(n1+n2+n3)
	Space Complexity - O(n1+n2+n3)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0,j=0,k=0;
            vector<int> commonNum;
            for(int i=0;i<n1;i++)
            {
                if(i>0)
                    if(A[i]==A[i-1])
                    {
                        continue;
                    }
                for(;j<n2;j++)
                {
                    if(j>0 &&B[j]==B[j-1])
                    {
                        continue;
                    }
                    if(A[i]==B[j])
                    {
                        for(;k<n3;k++)
                        {
                            if(A[i]==C[k])
                            {
                                if(k>0&&C[k]==C[k-1])
                                {
                                    continue;
                                }
                                commonNum.push_back(A[i]);
                                k++;
                                break;
                            }
                            else if(C[k]>A[i])
                            {
                                break;
                            }
                        }
                    }
                    if(B[j]>A[i])
                    {
                        break;
                    }
                }
            }
            return commonNum;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends
