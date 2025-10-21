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
    TreeNode* help(vector<int>&nums,int start, int end,  TreeNode*root){
        if(start>end)
        return root;

       int mid=(start+end)/2;
        root=new TreeNode(nums[mid]);

        root->left=help(nums,start,mid-1,root->left);
        root->right=help(nums,mid+1,end,root->right);

        return root;

    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;

        // int mid=(start+end)/2;

        TreeNode *root=help(nums,start,end,root);
        return root;
    }
};