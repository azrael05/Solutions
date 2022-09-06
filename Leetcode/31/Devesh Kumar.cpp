/*  
	Problem no. 31. Next Permutation
	Problem Link - https://leetcode.com/problems/next-permutation/
	
	Submitted by - Devesh Kumar
	 
	Time complexity - O(n)
	Space complexity - O(1)
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nextPermutation(vector<int>& nums) {
        int last=nums.size(),i,num;
        if(last==1)
        {
            return 0;
        }
        for(i=last-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                break;
        }
        if(i==-1)
        {
            reverse(nums.begin(),nums.end());
            return 0;
        }
        for(num=i+2;num<last;num++)
        {
            if(nums[num]<=nums[i])
            {
                num--;
                break;
            }
        }
        if(num==last)
            num--;
        swap(nums[i],nums[num]);
        reverse(nums.begin()+i+1,nums.end());
        return 0;
    }
};

int main()
{
	Solution s;
	vector<int> v;
	int n,num;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		v.push_back(num);
	}
	s.nextPermutation(v);
	for(int i=0;i<n;i++)
	{
		cout<<v[i];
	}
}
