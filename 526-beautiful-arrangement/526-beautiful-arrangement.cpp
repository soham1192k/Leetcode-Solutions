class Solution {
public:
    map<int,vector<int>>multiple,divisor;
    int dp[(1<<15)][16];
    int func(int mask,int idx){
        if(idx==0) return 1;
        if(dp[mask][idx]!=-1) return dp[mask][idx];
        int ans=0;
        for(auto x:multiple[idx]){
            if(mask&(1<<(x-1))){
                ans+=func(mask^(1<<(x-1)),idx-1);
            }
        }
        for(auto x:divisor[idx]){
            if(mask&(1<<(x-1))){
                ans+=func(mask^(1<<(x-1)),idx-1);
            }
        }
        return dp[mask][idx]=ans;
    }
    int countArrangement(int n) {
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=2;;j++){
                if(j*i<=n) multiple[i].push_back(j*i);
                else break;
            }
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    divisor[i].push_back(j);
                    if(i!=j*j) divisor[i].push_back(i/j);
                }
            }
        }
        return func((1<<n)-1,n);
    }
};