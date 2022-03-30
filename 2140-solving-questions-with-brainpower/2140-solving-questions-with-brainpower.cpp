class Solution {
public:
    long long dp[100005];
    long long func(vector<vector<int>>&questions,int pos,int n){
        if(pos<=0){
            return 0;
        }
        if(dp[pos]!=-1) return dp[pos];
        long long ans=0;
        ans=max(func(questions,pos-1,n),func(questions,pos-questions[pos-1][1]-1,n)+questions[pos-1][0]);
        return dp[pos]=ans;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        reverse(questions.begin(),questions.end());
        memset(dp,-1,sizeof(dp));
        return func(questions,n,n);
    }
};