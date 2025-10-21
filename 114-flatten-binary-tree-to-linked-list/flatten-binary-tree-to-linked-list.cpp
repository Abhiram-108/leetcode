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
    void help(TreeNode*node, TreeNode* &prev){
        if(node==NULL)
        return;

        help(node->right,prev);
        help(node->left,prev);

        node->right=prev;
        node->left=NULL;
        prev=node;

        return;

    }
public:
    void flatten(TreeNode* root) {
            TreeNode*prev=NULL;

            help(root,prev);
        
    }
};