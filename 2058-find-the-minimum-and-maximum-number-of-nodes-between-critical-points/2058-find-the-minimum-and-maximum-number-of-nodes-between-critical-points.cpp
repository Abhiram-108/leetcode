/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans(2,-1);
        vector<int>temp;
        vector<int>index;
        while(head){
            temp.push_back(head->val);
            head=head->next;
        }
        for(int i=1;i<temp.size()-1;i++){
            if(temp[i-1]<temp[i] && temp[i]>temp[i+1]   || temp[i-1]>temp[i] && temp[i]<temp[i+1])
           
                index.push_back(i);
        }
        if(index.size()<2)return ans;
        int mini=INT_MAX;
        for(int i=1;i<index.size();i++){
            mini=min(mini,index[i]-index[i-1]);
        }
        int maxi=index.back()-index.front();
        ans[0]=mini;
        ans[1]=maxi;
        return ans;
        
    }
};