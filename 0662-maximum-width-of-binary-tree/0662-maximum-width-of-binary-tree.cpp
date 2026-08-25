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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        unsigned long long ans=0;
        queue<pair<TreeNode*, unsigned long long>>q;
        q.push({root,0});

        while(!q.empty())
        {
            int n=q.size();
            unsigned long long start=0;
            unsigned long long end=0;

            for(int i=0; i<n; i++)
            {
                auto [curr,idx]=q.front();
                q.pop();

                if(i==0) start=idx;
                if(i==n-1) end=idx;

                if(curr->left)
                {
                    q.push({curr->left,2*idx+1});
                }

                if(curr->right)
                {
                    q.push({curr->right,2*idx+2});
                }
            }

            ans=max(ans,end-start+1);
        }
        return ans;
    }
};