class Solution {
    private:
    int help(string s,string t){
        unordered_map<char,int>mp;
       for(int i=0;i<s.size();i++){
           mp[s[i]]++;
           mp[t[i]]--;
       }
        for(auto it:mp){
            if(it.second!=0)
                return 0;
        }
        return 1;
        
    }
public:
    bool checkInclusion(string s1, string s2) {
        //basically s1 is a substring of s2
        int m=s1.size();
        int n=s2.size();
        for(int i=0;i<n-m+1;i++){
            string temp=s2.substr(i,m);
            if(help(s1,temp))
                return true;
            
        }
        return false;
        
    }
};