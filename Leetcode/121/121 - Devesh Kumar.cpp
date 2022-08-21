/*	
	Problem statement - 121 Best time to buy and sell stocks
	Porblem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
	
	Submitted by - Devesh Kumar
	
	Time complexity - O(n)
	Space complexity - O(n)
*/
//#include<bits/stdc++.h>
//
//using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> min, max;
        int mini=prices[0],maxi=prices[prices.size()-1],n=prices.size();
        for(int i=0;i<n;i++)
        {
            if(mini>prices[i])
            {
                mini=prices[i];
            }
            min.push_back(mini);
            if(maxi<prices[n-i-1])
            {
                maxi=prices[n-i-1];
            }
            max.push_back(maxi);
        }
        int profit;
        maxi=0;
        for(int i=0;i<n;i++)
        {
            profit=max[n-i-1]-min[i];
            if(profit>maxi)
            {
                maxi=profit;
            }
        }   
        return maxi;
    }
};

//int main()
//{
//	Solution s;
//	srand(time(0));
//	vector<int> v;
//	cout<<"Prices vector:- ";
//	for(int i=0;i<10;i++)
//	{
//		int num=rand()%(100)+1;
//		cout<<num<<" ";
//		v.push_back(num);
//	}
//	cout<<endl;
//	cout<<s.maxProfit(v);
//}
