class Solution {
    vector<int> find_psee(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }
        return pse;
    }

    vector<int> find_nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }
        return nse;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        vector<int> nse = find_nse(arr);
        vector<int> pse = find_psee(arr);
        int n = arr.size();

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long r = nse[i] - i;
            long long l = i - pse[i];
            sum = (sum + (r * l % mod * arr[i] % mod)) % mod;
        }

        return sum;
    }
};
