class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        int right=n-1;
        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]<nums[right])
            right=mid;
            else
            left=mid+1;
        }
        return nums[left];
    }
};