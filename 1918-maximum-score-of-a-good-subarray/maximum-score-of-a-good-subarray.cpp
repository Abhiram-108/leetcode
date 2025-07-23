class Solution {
    vector<int> find_nse(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> find_pse(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        vector<int> pse = find_pse(nums);
        vector<int> nse = find_nse(nums);
        int val = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (pse[i] < k && nse[i] > k) {
                val = max(val, nums[i] * (nse[i] - pse[i] - 1));
            }
        }
        return val;
    }
};
