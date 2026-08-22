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
    pair<int,int> helper(TreeNode* root)
    {
        if(root==NULL) return {0,0};

        pair<int,int> leftInfo=helper(root->left);
        pair<int,int> rightInfo=helper(root->right);

        int currDiam=leftInfo.second+rightInfo.second+1;
        int diam=max(currDiam,max(leftInfo.first,rightInfo.first));
        int ht=max(leftInfo.second,rightInfo.second)+1;
        return {diam,ht};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).first-1;
    }
};