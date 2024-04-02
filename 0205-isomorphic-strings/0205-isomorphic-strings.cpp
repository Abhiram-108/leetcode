class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,int>mp1,mp2;
        for(auto &it:s){
            if(mp1.count(it)!=0)
                continue;
            mp1[it]=mp1.size();
        }
         for(auto &it:t){
            if(mp2.count(it)!=0)
                continue;
            mp2[it]=mp2.size();
        }
        for(int i=0;i<s.length();i++){
            if(mp1[s[i]]!=mp2[t[i]])
                return false;
        }
        return true;
    }
};