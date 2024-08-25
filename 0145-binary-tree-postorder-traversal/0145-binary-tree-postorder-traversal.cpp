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
    void help(vector<int>&ans,TreeNode* root){
        if(root==NULL)
            return
        help(ans,root->left);
        help(ans,root->right);
        ans.push_back(root->val);
        return;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int>a;
        if(root==NULL)
        return a;
        vector<int>left=postorderTraversal(root->left);
        a.insert(a.end(),left.begin(),left.end());
        vector<int>right=postorderTraversal(root->right);
        a.insert(a.end(),right.begin(),right.end());
        a.push_back(root->val);
        return a;
    }
};