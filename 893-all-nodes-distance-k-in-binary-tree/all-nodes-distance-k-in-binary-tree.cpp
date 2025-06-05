/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void domap(map<TreeNode*,TreeNode*>&mp,TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
        TreeNode*current=q.front();
        q.pop();
        if(current->left){
            mp[current->left]=current;
            q.push(current->left);
        }
        if(current->right){
            mp[current->right]=current;
            q.push(current->right);
        }
        }

    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mp;
        domap(mp,root);
        map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int currentlevel=0;

        while(q.size()){
            if(currentlevel==k)
            break;
            
            currentlevel++;
            int n=q.size();
            for(int i=0;i<n;i++){

            TreeNode* current=q.front();
            q.pop();
            if(current->left && !vis[current->left])
            {
                vis[current->left]=1;
                q.push(current->left);
            }
            if(current->right && !vis[current->right])
            {
                vis[current->right]=1;
                q.push(current->right);
            }
            if(mp[current] && !vis[mp[current]]){
                vis[mp[current]]=1;
                q.push(mp[current]);
            }
        }}
        vector<int>ans;
        while(q.size()){
            TreeNode*current=q.front();
            q.pop();
            ans.push_back(current->val);
        }
        return ans;
    }
};