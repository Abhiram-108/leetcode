class Solution {
public:
    string removeDuplicates(string s, int k) {
      vector<pair<char,int>>st;
        int n=s.size();
        for( auto & it:s){
            if(!st.empty() && st.back().first==it){
                st.back().second=(st.back().second+1)%k;
                
            if(st.back().second==0){
                st.pop_back();
            }
            }
        else{
            st.push_back({it,1});
        }
        }
        
        string result="";
        
        for(auto &[character,count]:st){
            result+=string(count,character);
            
        }
        return result;
        
    }
};