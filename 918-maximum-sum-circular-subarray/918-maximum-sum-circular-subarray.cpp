class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int curr=nums[0],minn=nums[0],maxx=nums[0],curr1=nums[0],sum=nums[0];
        bool allneg=true;
        if(nums[0]>=0) allneg=false;
        for(int i=1;i<n;i++){
            if(nums[i]>=0) allneg=false;
            sum+=nums[i];
            curr=min(nums[i],nums[i]+curr);
            curr1=max(nums[i],nums[i]+curr1);
            minn=min(minn,curr);
            maxx=max(maxx,curr1);
        }
        if(allneg) return maxx;
        return max(maxx,sum-minn);
    }
};