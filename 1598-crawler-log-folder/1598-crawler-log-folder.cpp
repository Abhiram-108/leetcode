class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string>ans;
        int n=logs.size();
        for(int i=0;i<n;i++){
            if(logs[i]!="../" && logs[i]!= "./" ){
                ans.push_back(logs[i]);
            }
            if(logs[i]=="../" && ans.size()>0)
                ans.pop_back();
        }
        int m=ans.size();
        return m;
    }
};