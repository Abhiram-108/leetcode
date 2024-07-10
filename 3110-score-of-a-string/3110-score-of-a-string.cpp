class Solution {
public:
    int scoreOfString(string s) {
        int x=s[0]-'0';
        int ans=0;
        for(int i=1;i<s.length();i++){
            ans+=abs((s[i]-'0')-x);
            x=s[i]-'0';
        }
        return ans;
    }
};