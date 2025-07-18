class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(auto it:nums){
            sum+=it;

        }
        int leftsum=0;
        for(int i=0;i<nums.size();i++){
            int temp=sum-nums[i]-leftsum;
            if(leftsum==temp)
            return i;
            leftsum+=nums[i];
        }
        return -1;
    }
};