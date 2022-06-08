class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minn=1e9;
        int profit=0;
        for(int i=0;i<n;i++){
            if(minn>prices[i]) minn=prices[i];
            else{
                profit=max(profit,prices[i]-minn);
            }
        }
        return profit;
    }
};