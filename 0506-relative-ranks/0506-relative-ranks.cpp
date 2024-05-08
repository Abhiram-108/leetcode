class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        int n=score.size();
        vector<string>ans(n);
        for(int i=0;i<n;i++)
            pq.push({score[i],i});
        
        int num=1;
        vector<string> rank = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int index=it.second;
            if(num<4)
                ans[index]=rank[num-1];
            else
                ans[index]=to_string(num);
            num++;
        }
        return ans;
        
    }
};