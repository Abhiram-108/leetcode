class Solution {
    int help(int sum, map<int,int>&mp,int x){
        int ct=0;
        for(int i=1;i<=x;i++){
            if(x % i == 0){
            ct++;
            sum+=i;
            if(ct>4)
            break;
            }


        }
        
        if(ct==4)
        {
            mp[x]=sum;
            return sum;
        }

        return 0;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()){
               sum+= help(0,mp,nums[i]);
            }
            else
            sum+=mp[nums[i]];
        }
        return sum;
        
    }
};