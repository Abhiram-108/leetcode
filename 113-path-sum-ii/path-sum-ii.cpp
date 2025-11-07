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
    void help(TreeNode*root,int targetsum,vector<vector<int>>&res,vector<int>path){
        if(root==NULL)
        return ;
        path.push_back(root->val);

        if(root->left==NULL && root->right==NULL){
            if(targetsum==root->val){
                res.push_back(path);
            }
        }
      
            help(root->left,targetsum-root->val,res,path);
            help(root->right,targetsum-root->val,res,path);
            
        
        path.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>path;
         help(root,targetSum,res,path);
         return res;
    }
};