class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>bankset(bank.begin(),bank.end());
        unordered_set<string>visited;
        int level=0;
        queue<string>q;
        q.push(start);
        visited.insert(start);
        while(q.size()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==end)
                    return level;
                for(auto ch:"ACGT"){
                    for(int i=0;i<curr.size();i++){
                        string temp=curr;
                        temp[i]=ch;
                        if(visited.find(temp)==visited.end() && bankset.find(temp)!=bankset.end())
                        {
                            visited.insert(temp);
                            q.push(temp);
                        }
                    }
                    
                }
            }
            level++;
        }
        return -1;
    }
};