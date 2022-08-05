class Solution {
public:
    static const int mod=1e9+7;
    map<int,vector<int>>mp;
    int dp[41][(1<<10)+2];
    int func(int curr,int mask,int n){
        if(__builtin_popcount(mask)==n) return 1;
        if(curr==41) return 0;
        if(dp[curr][mask]!=-1) return dp[curr][mask];
        long long ans=0;
        ans=(ans+func(curr+1,mask,n))%mod;
        for(auto x:mp[curr]){
            if(!(mask&(1<<x))) ans=(ans+func(curr+1,mask|(1<<x),n))%mod; 
        }
        return dp[curr][mask]=ans;
    }
    int numberWays(vector<vector<int>>& hats) {
        memset(dp,-1,sizeof(dp));
        int n=hats.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<hats[i].size();j++){
                mp[hats[i][j]].push_back(i);
            }
        }
        return func(1,0,n);
    }
};