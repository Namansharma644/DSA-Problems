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
    int res=0;
    int DFS(TreeNode* root,int start)
    {
        if(root==NULL) return 0;

        int leftHeight=DFS(root->left,start);
        int rightHeight=DFS(root->right,start);

        if(root->val==start)
        {
            res=max(leftHeight,rightHeight);
           return -1;
        }
        else if(leftHeight>=0 && rightHeight>=0)
        {
           return max(leftHeight,rightHeight)+1;
        }
        else
        {
            int d=abs(leftHeight)+abs(rightHeight);
            res=max(res,d);
            return min(leftHeight,rightHeight)-1;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        DFS(root,start);
        return res;
    }
};