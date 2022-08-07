class Solution {
public:
    int dp[505][505];
    int func(vector<int>&a,int n,int idx,int curr){
        if(idx==n) return 0;
        if(dp[idx][curr]!=-1) return dp[idx][curr];
        int ans=0;
        ans=max(ans,func(a,n,idx+1,curr));
        ans=max(ans,curr*a[idx]+func(a,n,idx+1,curr+1));
        return dp[idx][curr]=ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        memset(dp,-1,sizeof(dp));
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        return func(satisfaction,n,0,1);
    }
};