/* Problem number - 409 Longest Palindrome
	Problem Link - https://leetcode.com/problems/longest-palindrome
	
	Submitted by - Devesh Kumar
	
	Time complexity - O(n)
	Space complexity - O(1)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int number_of_occourance_of_letter[52];
        for(int position=0;position<52;position++)
        {
            number_of_occourance_of_letter[position]=0;
        }
        int count_of_twice_occouring_letters=0;
        for(int position=0;position<s.length();position++)
        {
            if(islower(s[position]))
            {
                number_of_occourance_of_letter[s[position]-71]++;
                if(number_of_occourance_of_letter[s[position]-71]==2)
                {
                    count_of_twice_occouring_letters+=2;
                    number_of_occourance_of_letter[s[position]-71]=0;
                }
                
            }
            else
            {
                number_of_occourance_of_letter[s[position]-65]++;
                if(number_of_occourance_of_letter[s[position]-65]==2)
                {
                    count_of_twice_occouring_letters+=2;
                    number_of_occourance_of_letter[s[position]-65]=0;
                }
            }
        }
        if(count_of_twice_occouring_letters==s.length())
            return count_of_twice_occouring_letters;
        else
            return count_of_twice_occouring_letters+1;
    }
};

int main()
{
	Solution s;
	string po="abccccdd";
	cout<<s.longestPalindrome(po);
}
