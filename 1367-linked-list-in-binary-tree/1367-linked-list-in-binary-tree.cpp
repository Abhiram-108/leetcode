/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int checkpath(ListNode*head,TreeNode* root){
        if(head==NULL)
            return 1;
        if(root==NULL || head->val!=root->val )
            return 0;
        return checkpath(head->next,root->left) ||checkpath(head->next,root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL)
            return false;
        if(checkpath(head,root))
            return true;
        return isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};