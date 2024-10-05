class Solution {
    int binarysearch(vector<int>&nums,int low,int high,int target){
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                high=mid-1;
            if(nums[mid]<target)
                low=mid+1;
                
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
       //  int n=nums.size();
       //  int ans=binarysearch(nums,0,n-1,target);
       // return ans;
        int ind=0;
        for(auto it:nums){
            if(it==target)
                return ind;
            ind++;
        }
        return -1;
        
    }
};