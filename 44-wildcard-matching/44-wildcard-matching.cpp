class Solution {
public:
    int func(string& s,string& t,int idx_s,int idx_t,vector<vector<int>>&dp){
        if(idx_s<0&&idx_t<0) return 1;
        if(idx_t<0) return 0;
        if(idx_s<0) return (t[idx_t]=='*'&&func(s,t,idx_s,idx_t-1,dp));
        if(dp[idx_s][idx_t]!=-1) return dp[idx_s][idx_t];
        int ans;
        if(t[idx_t]=='*') ans=func(s,t,idx_s,idx_t-1,dp)||func(s,t,idx_s-1,idx_t,dp);
        else if(t[idx_t]=='?'||s[idx_s]==t[idx_t]) ans=func(s,t,idx_s-1,idx_t-1,dp);
        else ans=false;
        return dp[idx_s][idx_t]=ans;
    }
    bool isMatch(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(s,t,n-1,m-1,dp);
    }
};


