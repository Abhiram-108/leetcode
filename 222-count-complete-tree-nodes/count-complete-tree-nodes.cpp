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
    int help(TreeNode*root,int &ct){
        if(root==NULL)
        return 0;
        
       ct+=1;
        help(root->left,ct);
     
        help(root->right,ct);

        return ct;
    }
public:
    int countNodes(TreeNode* root) {
        int ct=0;
        return help(root,ct);
    }
};