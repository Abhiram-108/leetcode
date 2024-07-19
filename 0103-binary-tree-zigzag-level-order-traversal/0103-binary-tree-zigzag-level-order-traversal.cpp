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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>>ans;
        vector<int>temp;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(root);
        
        while(s1.size() || s2.size()){
              vector<int>temp1;
              vector<int>temp;
            while(s1.size()){
                TreeNode* x=s1.top();
                s1.pop();
                temp.push_back(x->val);
                if(x->left)
                    s2.push(x->left);
                if(x->right)
                    s2.push(x->right);
            
                    
                      
            }if(temp.size())
             ans.push_back(temp);
            
            while(s2.size()){
    
                TreeNode*x=s2.top();
                s2.pop();
                temp1.push_back(x->val);
                if(x->right)
                    s1.push(x->right);
                if(x->left)
                    s1.push(x->left);
                
            
            }if(temp1.size())
              ans.push_back(temp1);

        }
        return ans;
        
    }
};