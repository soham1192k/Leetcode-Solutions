class Solution {
public:
    int dp[370];
    int func(vector<int>&days,vector<int>&costs,int pos,int n){
        if(pos<=-1) return 0;
        if(dp[pos]!=-1) return dp[pos];
        int ans=1e9;
        ans=min(ans,func(days,costs,pos-1,n)+costs[0]);
        auto itr=upper_bound(days.begin(),days.end(),days[pos]-7);
        if(itr!=days.begin()){
            itr--;
            ans=min(ans,func(days,costs,itr-days.begin(),n)+costs[1]);
        }
        else ans=min(ans,costs[1]);
        itr=upper_bound(days.begin(),days.end(),days[pos]-30);
        if(itr!=days.begin()){
            itr--;
            ans=min(ans,func(days,costs,itr-days.begin(),n)+costs[2]);
        }
        else ans=min(ans,costs[2]);
        return dp[pos]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        memset(dp,-1,sizeof(dp));
        return func(days,costs,n-1,n);
    }
};