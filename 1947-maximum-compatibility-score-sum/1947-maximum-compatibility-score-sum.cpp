class Solution {
public:
    int m,n;
    int dp[9][(1<<8)+10];
    int func(vector<vector<int>>&students,vector<vector<int>>&mentors,int idx,int mask){
        if(idx<0||mask==0) return 0;
        if(dp[idx][mask]!=-1) return dp[idx][mask];
        int ans=0;
        int n_mask=0;
        for(int i=0;i<m;i++){
            if(mask&(1<<i)){
                n_mask=mask^(1<<i);
                int compatibility=0;
                for(int qsn=0;qsn<n;qsn++){
                    if(students[idx][qsn]==mentors[i][qsn]) compatibility++;
                }
                ans=max(ans,compatibility+func(students,mentors,idx-1,n_mask));
            }
        }
        return dp[idx][mask]=ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        memset(dp,-1,sizeof(dp));
        m=mentors.size();
        n=students[0].size();
        return func(students,mentors,m-1,(1<<m)-1);
    }
};