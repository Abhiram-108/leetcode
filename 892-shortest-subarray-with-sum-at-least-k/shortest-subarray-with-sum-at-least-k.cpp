class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        int n=nums.size();
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
        long long res=1e9;
        long long currsum=0;
       
        for(long long i=0;i<n;i++){
          currsum+=nums[i];
          if(currsum>=k){
            res=min(res,i+1);
          }
          while(pq.size() && (currsum-pq.top().first)>=k){
            res=min(res,i-pq.top().second);
            pq.pop();
          }
          pq.push({currsum,i});

        }
        if(res==1e9)
        return -1;
        else
        return res;
        
    }
};