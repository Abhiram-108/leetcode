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
    vector<int> help2(TreeNode*root){
        if(root==NULL){
         vector<int>ans(2,0);
         return ans;}

        vector<int>left=help2(root->left);
        vector<int>right=help2(root->right);
        
        vector<int>a(2,0);
        a[0]=root->val+left[1]+right[1];

        a[1]=max(left[0],left[1])+max(right[0],right[1]);

        return a;
    }


    int help(TreeNode*root){
        vector<int>ans=help2(root);
        return max(ans[0],ans[1]);
        
    }
public:
    int rob(TreeNode* root) {
        return help(root);
        
    }
};