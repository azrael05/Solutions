/*
	Problem No. - 287. Find the Duplicate Number
	Problem Link- https://leetcode.com/problems/find-the-duplicate-number/
	
	Submitted by - Devesh Kumar
	
	Time complexity - O(n)
	Space Complexity- O(n)
*/ 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> frequency_of_number(100001,0);
        for(int position=0;position<nums.size();position++)
        {
            if(frequency_of_number[nums[position]]!=0)
                return nums[position];
            else
                frequency_of_number[nums[position]]++;
        }
        return -1;
    }
};



