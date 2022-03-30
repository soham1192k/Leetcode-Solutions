class Solution {
public:
    const int mod=1e9+7;
    int numTilings(int n){
        if(n==1) return 1;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;dp[1]=1;dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i]+dp[i-2])%mod;
            dp[i]=(dp[i]+dp[i-1])%mod;
            for(int j=3;j<=i;j++){
                dp[i]=(dp[i]+dp[i-j])%mod;
                dp[i]=(dp[i]+dp[i-j])%mod;
            }
        }
        return dp[n];
    }
};