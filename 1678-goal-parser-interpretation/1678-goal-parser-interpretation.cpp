class Solution {
public:
    string interpret(string command) {
        int n=command.size();
        string ans;
        for(int i=0;i<n;i++){
            if(command[i]=='G')
                ans+='G';
           else if(command[i]=='(' && command[i+1]==')'){
                ans+='o';
                i++;
            }
            else{
                ans+='a';
                ans+='l';
                i=i+3;
            }
        }
        return ans;
    }
};