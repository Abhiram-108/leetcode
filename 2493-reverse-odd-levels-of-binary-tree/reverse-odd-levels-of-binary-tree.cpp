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

    void invert(TreeNode*left,TreeNode*right,int level){
        if(left==NULL || right==NULL)
        return ;

        if(level % 2==1)
        swap(left->val,right->val);

        invert(left->left,right->right,level+1);
        invert(left->right,right->left,level+1);
     

    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        int level=0;
        invert(root->left,root->right,level+1);

        return root;
        
    }
};