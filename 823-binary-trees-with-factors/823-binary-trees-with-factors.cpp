class Solution {
public:
    static const int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<long long>dp(n,1);
        map<int,int>mp;
        for(int i=0;i<n;i++) mp[arr[i]]=i+1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]!=0) continue;
                int right=arr[i]/arr[j];
                if(mp[right]) dp[i]=(dp[i]+(dp[j]*dp[mp[right]-1])%mod)%mod;
            }
        }
        long long val=0;
        for(int i=0;i<n;i++) val=(val+dp[i])%mod;
        return val;
    }
};