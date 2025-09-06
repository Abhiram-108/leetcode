class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string res = "";

        while (!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();

            int n = res.size();
            if (n >= 2 && res[n-1] == ch && res[n-2] == ch) {
                // Need to use the second most frequent character
                if (pq.empty()) break; // no alternative left → stop

                auto [freq2, ch2] = pq.top();
                pq.pop();

                res += ch2;
                freq2--;
                if (freq2 > 0) pq.push({freq2, ch2});

                // Push back ch (since we didn't use it yet)
                pq.push({freq, ch});
            } 
            else {
                res += ch;
                freq--;
                if (freq > 0) pq.push({freq, ch});
            }
        }

        return res;
    }
};
