class Solution {
    public int minDifference(int[] nums) {
        if(nums.length<=4)
            return 0;
        else{
            Arrays.sort(nums);
            int ans=nums[nums.length-1]-nums[0];
            for(int i=0;i<=3;i++){
                ans=Math.min(nums[nums.length-1-(3-i)]-nums[i],ans);
            }
            return ans;
        }
        
    }
}