class Solution {
public:
    const int mod=1e9+7;
    int dp[32][1002];
    int func(int pos,int n,int k,int target){
        if(pos==0){
            if(target==0) return 1;
            return 0;
        }
        if(dp[pos][target]!=-1) return dp[pos][target];
        int ans=0;
        for(int i=1;i<=min(target,k);i++) {
            ans=(ans+func(pos-1,n,k,target-i))%mod;
        }
        return dp[pos][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return func(n,n,k,target);
    }
};