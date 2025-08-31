class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        sort(nums.begin(),nums.end());
        int ct=0;
        while(l<r){
            ct+=abs(nums[r]-nums[l]);
            r--;
            l++;
        }
        return ct;
    }
};