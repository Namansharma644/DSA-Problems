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
    pair<bool,int> helper(TreeNode* root)
    {
        if(root==NULL) return {true,0};

        pair<bool,int> left=helper(root->left);
        pair<bool,int> right=helper(root->right);

        bool isVaild=(abs(left.second-right.second)<=1);
        bool ans=(left.first && right.first && isVaild);
        int ht=max(left.second,right.second)+1;
        return {ans,ht};
    }
    bool isBalanced(TreeNode* root) {
       return helper(root).first;
    }
};