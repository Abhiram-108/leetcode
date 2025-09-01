class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid + 1]) {
                // Peak is in the left part (including mid)
                r = mid;
            } else {
                // Peak is in the right part
                l = mid + 1;
            }
        }
        return l; // or r (both same when loop ends)
    }
};
