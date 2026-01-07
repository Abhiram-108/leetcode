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
    int help1(TreeNode*root){
        if(root==NULL)
        return 0;

        root->val+=(help1(root->left)+help1(root->right));
        return root->val;

    }
public:
    int maxProduct(TreeNode* root) {
        int mod=1e9+7;

     long long total=  help1(root);
     long long   ans=0;
        queue<TreeNode*>q;

        q.push(root);
        while(q.size()){
            TreeNode* node=q.front();
            q.pop();

          long long current=((total-node->val)* node->val);
            ans=max(ans,current);

            if(node->left)
            q.push(node->left);

            if(node->right)
            q.push(node->right);

        }

        return ans % mod;
        
    }
};