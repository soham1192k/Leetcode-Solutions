class Solution {
public:
    const int mod=1e9+7;
    int countPairs(vector<int>& arr) {
        int n=arr.size();
        int maxx=*max_element(arr.begin(),arr.end());
        vector<int>hold;
        for(int i=1;i<=2*maxx;i*=2) hold.push_back(i);
        map<int,int>mp;
        long long ans=0;
        for(int i=n-1;i>=0;i--){
            for(auto x:hold){
                if(x-arr[i]>=0) ans=(ans+mp[x-arr[i]])%mod;
            }
            mp[arr[i]]++;
        }
        return ans;
    }
};