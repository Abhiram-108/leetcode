class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cost=prices[0];
        int profit=0;
        int sum=0;
        for(int i=1;i<n;i++){
            sum=prices[i]-cost;
            profit=max(profit,sum);
            cost=min(cost,prices[i]);
        }
        return profit;
      

    }
};