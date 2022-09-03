class Solution {
public:
    int dp[1001][1001];
    int func(string&s,string&t,int idx_s,int idx_t){
        if(idx_t<0) return 1;
        if(idx_s<0) return 0;
        if(dp[idx_s][idx_t]!=-1) return dp[idx_s][idx_t];
        int ans=0;
        if(s[idx_s]==t[idx_t]) ans+=func(s,t,idx_s-1,idx_t-1);
        ans+=func(s,t,idx_s-1,idx_t);
        return dp[idx_s][idx_t]=ans;
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        memset(dp,-1,sizeof(dp));
        return func(s,t,n-1,m-1);
    }
};