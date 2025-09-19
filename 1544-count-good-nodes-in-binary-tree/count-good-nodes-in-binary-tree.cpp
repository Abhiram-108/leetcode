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
    void help(TreeNode*root, int &ct, int maxi){

        if(root==NULL)
        return;

        if(root->val>=maxi){
            ct++;
            maxi=root->val;
        }

        help(root->left,ct,maxi);
        help(root->right,ct,maxi);

        return;

    }
public:
    int goodNodes(TreeNode* root) {
        
        int ct=0;
        if(root==NULL)
        return ct;

        help(root,ct,root->val);

        return ct;
    }
};