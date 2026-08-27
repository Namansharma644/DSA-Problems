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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int st,int end,int &idx)
    {
        if(st>end) return NULL;

        int rootVal=preorder[idx];
        int i=st;
        for(; i<=end; i++)
        {
            if(inorder[i]==rootVal)
                break;
        }
        idx++;
        TreeNode* root=new TreeNode(rootVal);

        root->left=helper(preorder,inorder,st,i-1,idx);
        root->right=helper(preorder,inorder,i+1,end,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(n==0) return NULL;
        int idx=0;

        return helper(preorder,inorder,0,n-1,idx);
    }
};