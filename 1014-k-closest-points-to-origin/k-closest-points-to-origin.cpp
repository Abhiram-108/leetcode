class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            pq.push({points[i][0]*points[i][0] + points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(pq.size()>0){
            auto it=pq.top().second;
            ans.push_back({it.first,it.second});
            pq.pop();
        }
        return ans;

    }
};