class Solution {
public:
    int findDuplicate(vector<int>& nums) {

       int n=nums.size();
       int i=0;
       while(true){
        i=abs(nums[i]);
        if(nums[i]<0)
        return i;

        else
        nums[i]=-nums[i];
       }
        
    }
};