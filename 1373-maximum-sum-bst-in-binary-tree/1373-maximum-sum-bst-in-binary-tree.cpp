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
 class NodeValue {
    public:
    int largest;
    int smallest;
    int sum;
    NodeValue(int largest,int smallest,int sum)
    {
        this->largest=largest;
        this->smallest=smallest;
        this->sum=sum;
    }
 };
class Solution {
public:
    int ans=0;
    NodeValue helper(TreeNode* root)
    {
        if(root==NULL) return NodeValue(INT_MIN,INT_MAX,0);

        NodeValue leftInfo=helper(root->left);
        NodeValue rightInfo=helper(root->right);

        int currSum=leftInfo.sum+rightInfo.sum+root->val;
     

        if(leftInfo.largest<root->val && rightInfo.smallest>root->val)
        {
            ans=max(ans,currSum);
            return NodeValue(max(root->val,rightInfo.largest),min(root->val,leftInfo.smallest),currSum);
        }

        return NodeValue(INT_MAX,INT_MIN,0);
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
       return ans;
    }
};