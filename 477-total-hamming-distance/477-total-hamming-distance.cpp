class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        int cnt[32];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            for(int j=0;j<=30;j++){
                if(nums[i]&(1<<j)) cnt[j]++;
            }
        }
        int ans=0;
        for(int j=0;j<=30;j++){
            ans+=(cnt[j])*(n-cnt[j]);
        }
        return ans;
    }
};

