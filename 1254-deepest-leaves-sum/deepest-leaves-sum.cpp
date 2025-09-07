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
    void help(vector<vector<int>>&ans, TreeNode*root,int level){
        if(root==NULL)
        return;

        if(level>=ans.size()){
            vector<int>temp;
            ans.push_back(temp);
        }

        ans[level].push_back(root->val);
        help(ans,root->left,level+1);
        help(ans,root->right,level+1);
    }
public:

    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>>ans;
        
        help(ans,root,0);
        int n=ans.size();
        int sum=0;

        for(auto it:ans[n-1]){
            sum+=it;
        }

        return sum;




    }
};