class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp, ans;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                temp+=s[i];
                count++;
                
            }
            else if(s[i]==')' && count>0){
                temp+=s[i];
                count--;
                
            }
            else if(s[i]!='(' && s[i]!=')')
                temp+=s[i];
        }
        for(int i=temp.length()-1;i>=0;i--){
            if(temp[i]=='(' && count>0){
                count--; 
            }
            else
                ans+=temp[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};