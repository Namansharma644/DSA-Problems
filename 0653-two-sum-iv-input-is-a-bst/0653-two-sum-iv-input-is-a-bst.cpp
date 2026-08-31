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
class BSTIterator {
private: 
    stack<TreeNode*>s;
     void pushAll(TreeNode* root)
     {
        TreeNode* curr=root;
        while(curr)
        {
            s.push(curr);
            if(!reverse)
            {
              curr=curr->left;
            }
            else
            {
                curr=curr->right;
            }
        }  
    }

    bool reverse=true;
public:
    BSTIterator(TreeNode* root,bool isReverse) {
        reverse=isReverse;
        pushAll(root);
    }
    
    int next() {
        auto curr=s.top();
        s.pop();
        if(!reverse)
        {
            if(curr->right) pushAll(curr->right);
        }
        else
        {
            if(curr->left) pushAll(curr->left);
        }
        return curr->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i=l.next();
        int j=r.next();

        while(i<j)
        {
            if(i+j==k) return true;

            if(i+j>k)
            {
                j=r.next();
            }
            else
            {
                i=l.next();
            }
        }
        return false;
    }
};