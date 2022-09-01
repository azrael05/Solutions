/* 
	Problem Number - 724. Find Pivot Index
	Problem Link - https://leetcode.com/problems/find-pivot-index/
	
	Submitted By - Devesh Kumar
	Time complexity - O(n)
	Space complexity - O(1)

*/ 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right_sum=0,left_sum=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            right_sum=right_sum+nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(i>0)
                left_sum=left_sum+nums[i-1];
            right_sum=right_sum-nums[i];
            if(left_sum==right_sum)
            {
                return i;
            }
        }
        return -1;
    }
};
