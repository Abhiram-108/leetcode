class Solution {

    int ispalindromic(string&s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])
            return false;
        }
        return true;

    }
    void help(string s,int index ,vector<vector<string>>&res,vector<string>&path){
        if(index==s.size()){
            res.push_back(path);
            return;
        }
    

        for(int i=index;i<s.size();i++){
            if(ispalindromic(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                help(s,i+1,res,path);
                path.pop_back();

            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        help(s,0,res,path);

        return res;
    }
};