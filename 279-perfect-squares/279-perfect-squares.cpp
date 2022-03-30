class Solution {
public:
    int numSquares(int n) {
        if(n==1) return 1;
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=1e9;
            for(int j=1;j*j<=i;j++) dp[i]=min(dp[i],dp[i-j*j]+1);
        }
        return dp[n];
    }
};