class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size();
        map<int,int>mp;
        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=(ans+mp[target-arr[i]-arr[j]])%mod;
            }
            mp[arr[i]]++;
        }
        return ans;
    }
};