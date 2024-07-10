class Solution {
public:
    string defangIPaddr(string s) {
        int n=s.length();
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]!='.'){
                ans+=s[i];
            }
            else{
                ans+='[';
                ans+='.';
                ans+=']';
            }
        }
        return ans;
        
    }
};