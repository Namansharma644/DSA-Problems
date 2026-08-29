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
    TreeNode* findLeftMost(TreeNode* root)
    {
        if(root->right==NULL)
        {
            return root;
        }

        return  findLeftMost(root->right);
    }
    TreeNode* helper(TreeNode* root)
    {
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;

        TreeNode* rightChild=root->right;
        TreeNode* leftMost=findLeftMost(root->left);
        leftMost->right=rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key) return helper(root);
        TreeNode* curr=root;
        while(curr)
        {
            if(curr->val>=key)
            {
                if(curr->left!=NULL && curr->left->val==key)
                {
                    curr->left=helper(curr->left);
                    break;
                }
                else
                {
                    curr=curr->left;
                }
            }
            else
            {
                if(curr->right!=NULL && curr->right->val==key)
                {
                    curr->right=helper(curr->right);
                    break;
                }
                else
                {
                    curr=curr->right;
                }
            }
        }
        return root;
    }
};