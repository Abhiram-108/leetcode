class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxindex=0;
       for(int i=0;i<nums.size();i++){
           if(i>maxindex)
               return 0;
           maxindex=max(maxindex,i+nums[i]);
       }
        return 1;
        
    }
};