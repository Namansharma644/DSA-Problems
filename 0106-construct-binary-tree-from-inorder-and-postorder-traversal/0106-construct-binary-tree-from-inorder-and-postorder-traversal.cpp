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
    unordered_map<int,int>m;
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int st,int end,int &idx)
    {
        if(st>end) return NULL;

        int rootVal=postorder[idx];
        int i=m[rootVal];
        idx--;
        TreeNode* root=new TreeNode(rootVal);
        root->right=helper(inorder,postorder,i+1,end,idx);
        root->left=helper(inorder,postorder,st,i-1,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int idx=n-1;

        for(int i=0; i<n; i++)
        {
            m[inorder[i]]=i;
        }
        return helper(inorder,postorder,0,n-1,idx);
    }
};