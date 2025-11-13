class Solution {
    bool static cmp(pair<int,int>p1,pair<int,int>p2){
        return p1.first<p2.first;
    }
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int k=0;
        int n=profit.size();
       vector<pair<int,int>>jobs;
       for(int i=0;i<n;i++){
        jobs.push_back({difficulty[i],profit[i]});
       }

       sort(jobs.begin(),jobs.end(),cmp);

       int index=0;
       sort(worker.begin(),worker.end());
       int most_profit=0;
       int ans=0;


      for(int i=0;i<worker.size();i++){
        while(index<jobs.size() && worker[i]>=jobs[index].first){
            most_profit=max(most_profit,jobs[index].second);

            index++;

        }
        ans+=most_profit;
      }

      return ans;
       
    }
};