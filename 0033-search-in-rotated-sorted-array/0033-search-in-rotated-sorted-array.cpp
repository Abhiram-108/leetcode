class Solution {
    int binarysearch(vector<int>&nums,int left,int right,int target){
       while (left <= right) 
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;

            if (nums[left] <= nums[mid]) 
            {
                if (target >= nums[left] && target < nums[mid]) right = mid - 1;
                else left = mid + 1;
            }
            else 
            {
                if (target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=binarysearch(nums,0,n-1,target);
       return ans;
        // int ind=0;
        // for(auto it:nums){
        //     if(it==target)
        //         return ind;
        //     ind++;
        // }
        // return -1;
        
    }
};