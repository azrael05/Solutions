/* Problem No. 98. Validate Binary Search Tree
	Link  - https://leetcode.com/problems/validate-binary-search-tree/
	
	Submitted by Devesh Kumar

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> check(TreeNode* head)
        {
        vector<int> result;
        if(head==NULL)
        {
            result.push_back(0);
            result.push_back(INT_MAX);
            result.push_back(INT_MIN);
            return result;
        }
        else
        {
            bool left_val=(head->left==NULL)?true:((head->left->val)<(head->val))?true:false;
            bool right_val=(head->right==NULL)?true:((head->right->val)>(head->val))?true:false;
            if(right_val&&left_val)
            {
                vector<int> lc,rc;
                lc=check(head->left);
                if(head->left!=NULL&&lc[2]==INT_MIN&&lc[2]==head->val)
                    lc[0]=-1;
                else if(head->left!=NULL&&lc[2]>=head->val)
                    lc[0]=-1;
                rc=check(head->right);
                if(head->right!=NULL&&rc[1]==INT_MAX&&rc[1]<=head->val)
                    rc[0]=-1;
                else if(head->right!=NULL&&rc[1]<=head->val)
                    rc[0]=-1;
                if(rc[0]==-1 || lc[0]==-1)
                {
                    result.push_back(-1);
                    result.push_back(min(head->val,lc[1]));
                    result.push_back(max(rc[2],head->val));
                    return result;
                }
                else
                {
                    result.push_back(0);
                    result.push_back(min(head->val,lc[1]));
                    result.push_back(max(rc[2],head->val));
                    return result;
                }
                }
                else
                {
                    result.push_back(-1);
                    result.push_back(INT_MAX);
                    result.push_back(INT_MIN);
                    return result;
                }
            }
        result.push_back(-1);
        result.push_back(INT_MAX);
        result.push_back(INT_MIN);
        return result;
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> n=check(root);
        if(n[0]==-1)
            return false;
        return true;
    }
};
