/*	Problem no. 235. Lowest Common Ancestor of a Binary Search Tree
	Problem Link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
	
	Submitted by - Devesh Kumar

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int search(TreeNode* head,int num,vector<TreeNode*> &v)
    {
        if(head==NULL)
        {
            return -1;
        }
        if(head->val==num)
        {
            v.push_back(head);
            return 0;
        }
        else
        {
            v.push_back(head);
            int l1=search(head->left,num,v);
            int l2=search(head->right,num,v);
            if(l1==-1&&l2==-1)
            {
                v.pop_back();
            }
            if(l2==0||l1==0)
                    return 0;
            else
            {
                return -1;
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     vector<TreeNode*> target1,target2;
        search(root,p->val,target1);
        search(root,q->val,target2);
        for(int i=0;i<min(target1.size()-1,target2.size()-1);i++)
        {
                if(target1[i+1]==target2[i+1])
                {
                    continue;
                }
                else
                {
                    return target1[i];
                }
            
        }
        int i=min(target1.size()-1,target2.size()-1);
        if(target1[i]==target2[i])
            return target1[i];
        return NULL;
    }
};
