class FreqStack {
    vector<vector<int>> a;               // a[i] stores elements with frequency i+1
    map<int, int> mp;                    // Frequency count for each element
    int maxi = 0;                        // Current max frequency

public:
    FreqStack() {
        a.resize(10005);                 // Large enough to handle frequencies
    }
    
    void push(int val) {
        mp[val]++;
        int freq = mp[val];
        if (freq >= a.size()) a.resize(freq + 1);  // Resize if needed
        a[freq - 1].push_back(val);
        maxi = max(maxi, freq);
    }
    
    int pop() {
        int val = a[maxi - 1].back();
        a[maxi - 1].pop_back();
        mp[val]--;
        if (a[maxi - 1].empty()) maxi--;  // Decrease max frequency if no elements left
        return val;
    }
};
