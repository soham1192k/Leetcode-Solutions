class Solution {
public:
    int dp[50005];
    int func(vector<int>&a,int n,int idx){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=INT_MIN;
        ans=max(ans,a[idx]-func(a,n,idx+1));
        if(idx+1<n) ans=max(ans,a[idx]+a[idx+1]-func(a,n,idx+2));
        if(idx+2<n) ans=max(ans,a[idx]+a[idx+1]+a[idx+2]-func(a,n,idx+3));
        return dp[idx]=ans;
    }
    string stoneGameIII(vector<int>&a) {
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        if(func(a,n,0)>0) return "Alice";
        else if(func(a,n,0)<0) return "Bob";
        return "Tie";
    }
};