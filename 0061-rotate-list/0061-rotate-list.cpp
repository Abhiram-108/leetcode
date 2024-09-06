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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * temp=head;
        if(head==NULL||head->next==NULL || k==0)
        return head;
     int x=1;
        while(temp->next){
            x=x+1;
            temp=temp->next;
        }
        
        temp->next=head;
        k=k%x;
        k=x-k;
        while(k--)
            temp=temp->next;
        
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};