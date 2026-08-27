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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>m;

        while(!q.empty())
        {
            int n=q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* curr=q.front().first;
                int c=q.front().second.first;
                int r=q.front().second.second;
                q.pop();

                m[c][r].insert(curr->val);

                if(curr->left)
                {
                    q.push({curr->left,{c-1,r+1}});
                }

                if(curr->right)
                {
                    q.push({curr->right,{c+1,r+1}});
                }
            }
        } 

        for(auto &col : m)
        {
            vector<int>temp;

            for(auto &row : col.second)
            {
                for(int val : row.second)
                {
                    temp.push_back(val);
                }
            }

            ans.push_back(temp);
        }  
       return ans; 
    }
};