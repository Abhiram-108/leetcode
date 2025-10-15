class Solution {
    int help(vector<int>&nums,int k, vector<int>&inc){
        for(int i=k;i<=nums.size()-k;i++){
            if(inc[i]>=k && inc[i+k] >=k)
            return 1;
        }
        return 0;
    }
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>inc(n+1,1);
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1])
            inc[i+1]+=inc[i];
            else
            inc[i+1]=1;
        }

        int l=1;
        int h=n/2;
        while(l<h){
            int mid=(l+h+1)/2;
            if(help(nums,mid,inc))
            l=mid;
            else
            h=mid-1;
        }
        return l;
        
    }
};