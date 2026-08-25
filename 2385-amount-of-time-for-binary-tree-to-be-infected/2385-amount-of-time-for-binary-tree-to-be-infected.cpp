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
    unordered_map<TreeNode*,TreeNode*>parent;
    TreeNode* startNode=NULL;
    void DFS(TreeNode* root,int start)
    {
        if(root==NULL) return;
        if(root->val==start) startNode=root;

        if(root->left) parent[root->left]=root;
        DFS(root->left,start);
        if(root->right) parent[root->right]=root;
        DFS(root->right,start);
    }
    int BFS(TreeNode* startNode)
    {
        queue<TreeNode*>q;
        unordered_set<int>vis;
        q.push(startNode);
        vis.insert(startNode->val);
        int time=0;

        while(!q.empty())
        {
            int n=q.size();
            time++;

            for(int i=0; i<n; i++)
            {
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left && !vis.count(curr->left->val))
                {
                    q.push(curr->left);
                    vis.insert(curr->left->val);
                }

                if(curr->right && !vis.count(curr->right->val))
                {
                    q.push(curr->right);
                    vis.insert(curr->right->val);
                }

                if(parent.count(curr) && !vis.count(parent[curr]->val))
                {
                    q.push(parent[curr]);
                    vis.insert(parent[curr]->val);
                }
            }
        }
        return time-1;
    }
    int amountOfTime(TreeNode* root, int start) {
        DFS(root,start);
        return BFS(startNode);
    }
};