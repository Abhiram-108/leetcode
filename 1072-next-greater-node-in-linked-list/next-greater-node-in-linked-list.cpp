class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // Step 1: Reverse the list properly
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev; // Now head points to the reversed list

        // Step 2: Use a stack to find next greater nodes
        stack<int> st;
        vector<int> ans;

        while (head) {
            while (!st.empty() && st.top() <= head->val)
                st.pop();

            if (st.empty())
                ans.push_back(0);
            else
                ans.push_back(st.top());

            st.push(head->val);
            head = head->next;
        }

        // Step 3: Reverse the result to match original order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
