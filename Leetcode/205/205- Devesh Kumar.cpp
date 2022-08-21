/*  Problem no. 205. Isomorphic Strings
	Problem link - https://leetcode.com/problems/isomorphic-strings/
	
	Submitted by Devesh Kumar
	LinkedIn - 
	
	Time complexity - O(nlogn)
	Space complexity - O(n)
*/

//#include<bits/stdc++.h>
//using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        set<char> used;
        int array[26];
        for(int i=0;i<26;i++)
        {
            array[i]=-1;
        }
        for(int i=0;i<s.length();i++)
        {
            map<char,char>::iterator itr;
            itr=mp.find(s[i]);
            if(itr==mp.end())
            {
            	if(used.find(t[i])!=used.end())
            	{
            		return false;
				}
            	used.insert(t[i]);
                mp.insert(pair<char,char>(s[i],t[i]));
                // array[t[i]];
            }
            else
            {
                if(t[i]==itr->second)
                    continue;
                else
                    return false;
            }
        }
		return true;
    }
};
//int main()
//{
//	Solution s;
//	cout<<s.isIsomorphic("hello","titts");
//}
