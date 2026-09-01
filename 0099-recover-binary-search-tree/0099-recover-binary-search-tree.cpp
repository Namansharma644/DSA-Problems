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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* adjacent;
    TreeNode* second;
    void helper(TreeNode* root)
    {
        if(root==NULL) return;
        helper(root->left);

        if(prev!=NULL && prev->val>root->val)
        {
            if(first==NULL)
            {
                first=prev;
                adjacent=root;
            }
            else
            {
                second=root;
            }
        }
        prev=root;

        helper(root->right);
    }

    void recoverTree(TreeNode* root) {
       prev = first = adjacent = second = NULL;
        helper(root);
        if(first && second)
        {
            swap(first->val,second->val);
        }
        else
        {
            swap(first->val,adjacent->val);
        }
    }
};