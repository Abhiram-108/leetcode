class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums2.size();
        vector<int>r(n);
        map<int,int>mp;
        for(int i=n-1;i>=0;i--){
            while(st.size() && nums2[st.top()]<=nums2[i])
            st.pop();

            if(st.size()==0)
            mp[nums2[i]]=-1;

            else
            mp[nums2[i]]=nums2[st.top()];


            st.push(i);
            

        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])!=mp.end())
            ans.push_back(mp[nums1[i]]);
        }

return ans;


    }
};