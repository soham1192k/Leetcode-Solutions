class Solution {
public:
    int dp[301];
    unordered_map<string,bool>mp;
    int func(string&s,int idx,int n){
        if(idx>=n) return 1;
        if(dp[idx]!=-1) return dp[idx];
        string curr="";
        int ans=0;
        for(int i=idx;i<n;i++){
            curr+=s[i];
            if(mp[curr]) ans|=func(s,i+1,n);
        }
        return dp[idx]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict){
        memset(dp,-1,sizeof(dp));
        int n=s.length();
        for(auto x:wordDict) mp[x]=true;
        return func(s,0,n);
    }
};