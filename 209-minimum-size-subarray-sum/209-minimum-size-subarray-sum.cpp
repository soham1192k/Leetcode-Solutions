class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int left=0;
        int minn=1e5+1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                minn=min(minn,i+1-left);
                sum-=nums[left++];
            }
        }
        if(minn==1e5+1) return 0;
        return minn;
    }
};