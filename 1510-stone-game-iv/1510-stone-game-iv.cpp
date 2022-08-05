class Solution {
public:
    bool winnerSquareGame(int n) {
        bool dp[n+1];
        memset(dp,false,sizeof(dp));
        dp[1]=true;
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(!dp[i-j*j]) dp[i]=true;
            }
        }
        return dp[n];
    }
};