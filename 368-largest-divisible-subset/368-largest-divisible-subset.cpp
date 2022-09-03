class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int p[n],dp[n];
        dp[0]=1;
        p[0]=-1;
        for(int i=1;i<n;i++){
            dp[i]=1;p[i]=-1;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                        p[i]=j;
                    }
                }
            }
        }
        int maxx=-1,idx=-1;
        for(int i=0;i<n;i++){
            if(maxx<dp[i]){
                maxx=dp[i];
                idx=i;
            }
        }
        vector<int>ans;
        int curr=idx;
        while(curr!=-1){
            ans.push_back(nums[curr]);
            curr=p[curr];
        }
        return ans;
    }
};