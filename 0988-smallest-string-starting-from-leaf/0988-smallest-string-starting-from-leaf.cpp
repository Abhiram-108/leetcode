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
    void f(TreeNode *root,string s,string &ans){
        if(root==NULL)
            return;
        s+=('a'+root->val);
        f(root->left,s,ans);
        if(root->left==NULL && root->right==NULL){
            string temp=s;
            reverse(temp.begin(),temp.end());
            if(ans.empty()||ans>temp)
                ans=temp;
            
        }
        f(root->right,s,ans);
        return ;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string s,ans;
         f(root,s,ans);
        return ans;
        
        
    }
};