/* 
	Problem Number - 70. Climbing Stairs
	Problem Link - https://leetcode.com/problems/climbing-stairs/
	
	Submitted By - Devesh Kumar
	Time complexity - O()
	Space complexity - O()

*/ 
vector<int> v{0,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040};

class Solution {
public:
    int next_step(int n)
    {
        int i=v[v.size()-2],j=v[v.size()-1];
        for(int count=0;count<n;count++)
        {
            int sum=i+j;
            i=j;
            j=sum;
        }
        return j;
    }
    int climbStairs(int n) {
        if(n<::v.size())
        {
            return ::v[n];
        }
        else
        {
            int count=next_step(n-29);
            return count;
        }
        return -1;
    }
};
