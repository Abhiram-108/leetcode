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
    private:
    void f(long long &sum,TreeNode*root){
        if(root==NULL)
            return;
       
        f(sum,root->left);
        if(root->left && !root->left->left && !root->left->right)sum+=root->left->val;
        f(sum,root->right);
        return;
        
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        long long sum=0;
        f(sum,root);
        return sum;
        
    }
};