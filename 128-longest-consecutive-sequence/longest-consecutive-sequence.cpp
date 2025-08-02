class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        int longest=0;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int ct=1;
                int x=it;
                while(st.find(x+1) !=st.end()){
                    ct++;
                    x++;
                }
                longest=max(ct,longest);
            }
        }
        return longest;
        
    }
};