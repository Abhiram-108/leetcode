class Solution {
    void help(int i, int k, int target, int sumtillnow,
              vector<int>& temp, vector<vector<int>>& ans) {
       
        if (sumtillnow > target) return;
        if (sumtillnow == target) {
            if (k == 0) ans.push_back(temp);
            return;
        }
         if (k < 0 || i == 10) return;

        // take i
        temp.push_back(i);
        help(i + 1, k - 1, target, sumtillnow + i, temp, ans);
        temp.pop_back();

        // skip i
        help(i + 1, k, target, sumtillnow, temp, ans);
    }

public:
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        help(1, k, target, 0, temp, ans); // start from 1
        return ans;
    }
};
