class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0||n==1) return false;
        int pre[n];
        pre[0]=nums[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];
        for(int i=0;i<n;i++) pre[i]%=k;
        map<int,int>mp;
        mp[0]=0;
        for(int i=0;i<n;i++){
            if(mp.find(pre[i])==mp.end()) mp[pre[i]]=i+1;
            else{
                if(i+1-mp[pre[i]]>1) return true;
            }
        }
        return false;
    }
};