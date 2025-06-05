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
        map<TreeNode*,TreeNode*>mp;
    void domake(TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            TreeNode* current=q.front();
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
 TreeNode* help(TreeNode* root, int x) {
    if (root == nullptr)
        return nullptr;
    if (root->val == x)
        return root;

    TreeNode* leftSearch = help(root->left, x);
    if (leftSearch != nullptr)
        return leftSearch;

    return help(root->right, x);
}
public:
    int amountOfTime(TreeNode* root, int start) {
    
        domake(root);
        map<TreeNode*,bool>vis;
        int currentlevel=0;
           queue<TreeNode*>q;
        TreeNode* x=help(root,start);
           q.push(x);
           vis[x]=true;
           while(q.size()){
            int n=q.size();
        
            
            for(int i=0;i<n;i++){
                TreeNode*current=q.front();
                q.pop();
                if(current->left && !vis[current->left]){
                    vis[current->left]=true;
                    q.push(current->left);
                }
                if(current->right && !vis[current->right]){
                    vis[current->right]=true;
                    q.push(current->right);
                }
                if(mp[current] && !vis[mp[current]]){
                    vis[mp[current]]=true;
                    q.push(mp[current]);

                }

            }
                currentlevel++;
           }

           return currentlevel-1;
        
    }
};