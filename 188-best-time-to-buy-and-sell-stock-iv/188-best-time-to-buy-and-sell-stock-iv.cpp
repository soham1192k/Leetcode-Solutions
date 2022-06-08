class Solution {
public:
    int dp[1001][101][2];
    int func(vector<int>&prices,int n,int idx,int left,int holding){
        if(idx<0) return 0;
        if(left==0) return 0;
        if(dp[idx][left][holding]!=-1) return dp[idx][left][holding];
        int op1=0,op2=0;
        if(holding==1){
            //sell
            op1=prices[idx]+func(prices,n,idx-1,left-1,holding^1);
            //dont sell
            op2=func(prices,n,idx-1,left,holding);
        }
        else{
            //buy
            if(left>=1) op1=-prices[idx]+func(prices,n,idx-1,left,holding^1);
            //dont buy
            op2=func(prices,n,idx-1,left,holding);
        }
        return dp[idx][left][holding]=max(op1,op2);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        reverse(prices.begin(),prices.end());
        return max(0,func(prices,n,n-1,k,0));
    }
};
