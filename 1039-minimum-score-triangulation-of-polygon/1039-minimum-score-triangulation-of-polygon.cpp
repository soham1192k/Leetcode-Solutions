class Solution {
public:
    int dp[51][51];
    int func(vector<int>&values,int i,int j){
        if(i>=j-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        for(int k=i+1;k<j;k++){
            ans=min(ans,func(values,i,k)+func(values,k,j)+values[i]*values[j]*values[k]);
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        int n=values.size(); 
        return func(values,0,n-1);
    }
};