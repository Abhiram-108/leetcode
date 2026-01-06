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
    void help(map<int,int>&mp,queue<pair<TreeNode*,int>>&q,TreeNode* root,int level){
        if(root==NULL)
        return;

        q.push({root,level});

        while(q.size()){


        auto data=q.front();
        q.pop();

        TreeNode* node=data.first;
        int level=data.second;

        mp[level]+=node->val;
        if(node->left)
        q.push({node->left,level+1});
        if(node->right)
        q.push({node->right,level+1});

        }

        return;


    }
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;

        map<int,int>mp;
        help(mp,q,root,0);

         int maxSum = INT_MIN;
        int ansLevel = 0;

        for (auto it : mp) {
            if (it.second > maxSum) {
                maxSum = it.second;
                ansLevel = it.first;
            }
        }

        return ansLevel+1; 


        
    }
};