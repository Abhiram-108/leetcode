class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string ans="";
        for(int i=0;i<words.size();i++){
            string temp=words[i];
            ans+=temp[0];
            
        }
        if(ans==s)
            return 1;
        return 0;
        
    }
};