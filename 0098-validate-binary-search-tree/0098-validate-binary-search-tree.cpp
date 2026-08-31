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
    bool isValidBST(TreeNode* root) {
         TreeNode* curr=root;
         TreeNode* prev=NULL;
         bool isVaild=true;

         while(curr)
         {
            if(curr->left==NULL)
            {
                if(prev!=NULL && prev->val>=curr->val) isVaild=false;
                prev=curr;
                curr=curr->right;
            }
            else
            {
                TreeNode* leftChild=curr->left;
                while(leftChild->right && leftChild->right!=curr)
                {
                    leftChild=leftChild->right;
                }

                if(leftChild->right==NULL)
                {
                    leftChild->right=curr;
                    curr=curr->left;
                }
                else
                {
                    leftChild->right=NULL;
                    if(prev!=NULL && prev->val>=curr->val) isVaild=false;
                    prev=curr;
                    curr=curr->right;
                }
            }
         }
         return isVaild;
    }
};