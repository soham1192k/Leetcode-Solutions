class Solution {
public:
    static const int mod=1e9+7;
    int dp[100001];
    int func(string&s,int idx){
        if(idx<0) return 1;
        if(dp[idx]!=-1) return dp[idx];
        int ans=0;
        long long val;
        //single
        if(s[idx]!='0'){
            if(s[idx]=='*'){
                val=(9ll*func(s,idx-1))%mod;
                ans=(ans+val)%mod;
            }
            else ans=(ans+func(s,idx-1))%mod;
        }
        //double
        if(idx>=1){
            if(s[idx]=='*'){
                if(s[idx-1]=='1'){
                    val=(9ll*func(s,idx-2))%mod;
                    ans=(ans+val)%mod;
                }
                else if(s[idx-1]=='2'){
                    val=(6ll*func(s,idx-2))%mod;
                    ans=(ans+val)%mod;
                }
                else if(s[idx-1]=='*'){
                    val=(15ll*func(s,idx-2))%mod;
                    ans=(ans+val)%mod;
                }
            }
            else{
                if(s[idx-1]=='*'){
                    if(s[idx]<='6'){
                        val=(2ll*func(s,idx-2))%mod;
                        ans=(ans+val)%mod;
                    }
                    else ans=(ans+func(s,idx-2))%mod;
                }
                else if(s[idx-1]=='1') ans=(ans+func(s,idx-2))%mod;
                else if(s[idx-1]=='2'){
                    if(s[idx]>='0'&&s[idx]<='6') ans=(ans+func(s,idx-2))%mod;
                }
            }
        }
        return dp[idx]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return func(s,s.length()-1);
    }
};