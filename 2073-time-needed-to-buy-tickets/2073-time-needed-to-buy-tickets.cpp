class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        for(int i=0;i<tickets.size();i++)
            q.push(i);
        int time=0;
        while(!q.empty()){
            time++;
            int front1=q.front();
            q.pop();
            tickets[front1]--;
            if(k==front1 && tickets[front1]==0)
                return time;
            if(tickets[front1]!=0)
                q.push(front1);
        }
        return time;
        
    }
};