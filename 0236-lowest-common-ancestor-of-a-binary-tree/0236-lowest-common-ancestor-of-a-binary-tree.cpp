/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root,TreeNode* n,vector<TreeNode*>&path)
    {
        if(root==NULL) return false;

        path.push_back(root);

        if(root->val==n->val) return true;

        bool left=solve(root->left,n,path);
        bool right=solve(root->right,n,path);

        if(left|| right) return true;

        path.pop_back();
        return false;  
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        solve(root,p,path1);
        solve(root,q,path2);

        int i=0;
        int j=0;

        while(i<path1.size() && j<path2.size())
        {
            if(path1[i]!=path2[j]) return ans;
            ans=path1[i];
            i++;
            j++;
        }
        return ans;
    }
};