/* 
	Problem No. 46. Permutations
	Problem Link - https://leetcode.com/problems/permutations/
	
	Submitted by - Devesh Kumar
	
	Time Complexity- 
	Space Complexity - 
*/

class Solution {
public:
    void per(vector<int>& nums,vector<vector<int>> &solutions,int current,int size)
    {
        if(current==size)
        {
            solutions.push_back(nums);
        }
        else
        {
            for(int i=current;i<size;i++)
            {
                swap(nums[current],nums[i]);
                per(nums,solutions,current+1,size);
                swap(nums[current],nums[i]);    
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solutions;
        per(nums,solutions,0,nums.size());
        return solutions;
    }
};
