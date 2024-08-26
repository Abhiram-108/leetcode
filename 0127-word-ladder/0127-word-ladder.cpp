class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordlist) {
        unordered_set<string>worddict(wordlist.begin(),wordlist.end());
        unordered_set<string>visited;
        int level=1;
        queue<string>q;
        q.push(begin);
        visited.insert(begin);
        while(q.size()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==end)
                    return level;
                for(char ch='a';ch<='z';ch++){
                   for(int i=0;i<curr.size();i++){
                       string temp=curr;
                       temp[i]=ch;
                       if(visited.find(temp)==visited.end() && worddict.find(temp)!=worddict.end())
                       {
                           q.push(temp);
                           visited.insert(temp);
                       }
                   }
                }
            }
            level++;
        }
        return 0;
        
    }
};