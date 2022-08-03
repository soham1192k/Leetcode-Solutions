class Solution {
public:
    static const int mod=1e9+7;
    int dp[100001][3];
    int func(string&s,int idx,int seats){
        if(idx<0){
            if(seats==2) return 1;
            return 0;
        }
        if(dp[idx][seats]!=-1) return dp[idx][seats];
        int ans=0;
        if(s[idx]=='P'){
            if(seats==2){
                if(idx-1>=0&&s[idx-1]=='S') ans=(ans+func(s,idx-1,0))%mod;
                else{
                    ans=(ans+func(s,idx-1,0))%mod;
                    ans=(ans+func(s,idx-1,seats))%mod;
                }
            }
            else{
                ans=(ans+func(s,idx-1,seats))%mod;
            }
        }
        else{
            if(seats==0){
                ans=(ans+func(s,idx-1,seats+1))%mod;
            }
            else if(seats==1){
                ans=(ans+func(s,idx-1,seats+1))%mod;
                ans=(ans+func(s,idx-1,0))%mod;
            }
        }
        return dp[idx][seats]=ans;
    }
    int numberOfWays(string s){
        memset(dp,-1,sizeof(dp));
        return func(s,s.length()-1,0);
    }
};