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
    void inOrder(TreeNode* root,vector<int>&nodes)
    {
        if(root==NULL) return;

        inOrder(root->left,nodes);
        nodes.push_back(root->val);
        inOrder(root->right,nodes);
    }
    int idx=-1;
    TreeNode* buildBst(vector<int>&nodes)
    {
        idx++;
        if(idx>=nodes.size()) return NULL;

        TreeNode* curr=new TreeNode(nodes[idx]);

        curr->left=NULL;
        curr->right=buildBst(nodes);
        return curr;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>nodes;
        inOrder(root,nodes);
        return buildBst(nodes);
    }
};