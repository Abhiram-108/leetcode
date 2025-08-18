class Solution {
public:
    const double TARGET = 24.0;
    const double EPS = 1e-6;

    bool solve(vector<double>& nums) {
        int n = nums.size();
        if (n == 0) return false;
        if (n == 1) {
            return fabs(nums[0] - TARGET) < EPS;
        }

        // Try all ordered pairs (i, j) with i != j
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                // Build next list excluding nums[i] and nums[j]
                vector<double> next;
                next.reserve(n - 1);
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    next.push_back(nums[k]);
                }

                double a = nums[i], b = nums[j];

                // a + b (commutative) - only do when i < j to avoid duplicate symmetric work
                if (i < j) {
                    next.push_back(a + b);
                    if (solve(next)) return true;
                    next.pop_back();
                }

                // a * b (commutative) - only do when i < j
                if (i < j) {
                    next.push_back(a * b);
                    if (solve(next)) return true;
                    next.pop_back();
                }

                // a - b (non-commutative)
                next.push_back(a - b);
                if (solve(next)) return true;
                next.pop_back();

                // a / b (non-commutative), avoid division by near-zero
                if (fabs(b) > EPS) {
                    next.push_back(a / b);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        nums.reserve(cards.size());
        for (int x : cards) nums.push_back(static_cast<double>(x));
        return solve(nums);
    }
};