class Solution {
public:
    static const int mod=1e9+7;
    int dp[20005][6];
    int func(int idx,int n,int no){
        if(idx>=n) return 1;
        if(dp[idx][no]!=-1) return dp[idx][no];
        long long ans=0;
        if(no==0){
            for(int i=1;i<=5;i++) ans=(ans+func(idx+1,n,i))%mod;
        }
        else if(no==1) ans=(ans+func(idx+1,n,2))%mod;
        else if(no==2){
            ans=(ans+func(idx+1,n,1))%mod;
            ans=(ans+func(idx+1,n,3))%mod;
        }
        else if(no==3){
            for(int i:{1,2,4,5}) ans=(ans+func(idx+1,n,i))%mod;
        }
        else if(no==4){
            ans=(ans+func(idx+1,n,3))%mod;
            ans=(ans+func(idx+1,n,5))%mod;
        }
        else ans=(ans+func(idx+1,n,1))%mod;
        return dp[idx][no]=ans;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        return func(0,n,0);
    }
};