class Solution {
public:
    int numJewelsInStones(string j, string s) {
        map<char,int>mp;
        int ans=0;
        for(int i=0;i<j.length();i++){
            mp[j[i]]++;
        }for(int i=0;i<s.length();i++){
            if(mp[s[i]])
                ans+=mp[s[i]];
        }
        return ans;
    }
};