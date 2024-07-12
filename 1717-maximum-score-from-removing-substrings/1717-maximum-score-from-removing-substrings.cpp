class Solution {
private:
    string stack_to_string(stack<char>& st) {
        string str = "";
        while (!st.empty()) {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
    int do_ab(string& s, int x, int y, int ans, stack<char>& st) {
        for (char c : s) {
            if (c == 'b' && st.size() > 0 && st.top() == 'a') {
                st.pop();
                ans += x;
            } else {
                st.push(c);
            }
        }
        return ans;
    }

    int do_ba(string& s, int x, int y, int ans, stack<char>& st) {
        for (char c : s) {
            if (c == 'a' && st.size() > 0 && st.top() == 'b') {
                st.pop();
                ans += y;
            } else {
                st.push(c);
            }
        }
        return ans;
    }

public:
    int maximumGain(string s, int x, int y) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int res = 0;
        stack<char> st;
        if (x > y) {
            res = do_ab(s, x, y, 0, st);
            s = stack_to_string(st);
            res += do_ba(s, x, y, 0, st);

        } else {
            res = do_ba(s, x, y, 0, st);
            s = stack_to_string(st);
            res += do_ab(s, x, y, 0, st);
        }

        return res;
    }
};