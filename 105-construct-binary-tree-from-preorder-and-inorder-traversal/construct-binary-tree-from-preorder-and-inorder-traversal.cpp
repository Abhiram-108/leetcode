class Solution {
    TreeNode* help(vector<int>& preorder, int pl, int pr,
                   vector<int>& inorder, int il, int ir,
                   map<int, int>& mp) {
        if (pl > pr || il > ir)
            return NULL;

        TreeNode* root = new TreeNode(preorder[pl]); // ✅ preorder[pl] is the root
        int index_root = mp[preorder[pl]];
        int num_left = index_root - il;

        root->left = help(preorder, pl + 1, pl + num_left,
                          inorder, il, index_root - 1, mp);

        root->right = help(preorder, pl + num_left + 1, pr,
                           inorder, index_root + 1, ir, mp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n != inorder.size())
            return NULL;

        map<int, int> mp;
        for (int i = 0; i < n; ++i)
            mp[inorder[i]] = i;

        return help(preorder, 0, n - 1, inorder, 0, n - 1, mp);
    }
};
