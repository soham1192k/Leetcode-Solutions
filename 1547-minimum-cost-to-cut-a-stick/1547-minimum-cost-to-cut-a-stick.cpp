class Solution {
public:
    int dp[102][102];
    int func(int low,int high,vector<int>&cuts){
        //base case
        if(low>=high-1) return 0;
        if(dp[low][high]!=-1) return dp[low][high];
        int cost=1e9;
        for(int i=low+1;i<=high-1;i++) cost=min(cost,cuts[high]-cuts[low]+func(low,i,cuts)+func(i,high,cuts));
        return dp[low][high]=cost;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int N=cuts.size()-1;
        return func(0,N,cuts);
    }
};