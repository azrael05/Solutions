/*
	Problem No. 125. Valid Palindrome
	Problem Link- https://leetcode.com/problems/valid-palindrome/
	
	Submitted by - Devesh Kumar
	
	Time complexity- O(n)
	Space complexity- O(1)
*/
class Solution {
public:
    bool isPalindrome(string s) {
     int i=0,j=s.length()-1;
     while(i<j)
     {
         if((tolower(s[i])>=97&&tolower(s[i])<=122)||(tolower(s[i])>=48&&tolower(s[i])<=57))
         {
             while(j>=0)
             {
             if((tolower(s[j])>=97&&tolower(s[j])<=122)||(tolower(s[j])>=48&&tolower(s[j])<=57))
             {
                if(tolower(s[i])!=tolower(s[j]))
                {
                    cout<<s[i]<<s[j]<<endl;
                    return false;
                }
                 else
                 {
                     i++;
                     j--;
                     break;
                 }
             } 
             else
             {
                 j--;
             }
             }
         }
        else
            i++;
    }
    return true;
    }
};
