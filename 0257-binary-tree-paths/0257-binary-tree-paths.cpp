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
    void helper(TreeNode* root,vector<string>&ans,string &temp)
    {
        if(root==NULL) return;

        int len=temp.size();

        temp+=to_string(root->val);

        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(temp);
           
        }
        else
        {
            temp+="->";

            helper(root->left,ans,temp);
            helper(root->right,ans,temp);
        }

        temp.resize(len);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp="";
        helper(root,ans,temp);
        return ans;
    }
};