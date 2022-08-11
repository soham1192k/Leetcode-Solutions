class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int idx=1;
        while(idx<=n){
            while(nums[idx-1]>0&&nums[idx-1]<=n&&nums[idx-1]!=idx&&nums[idx-1]!=nums[nums[idx-1]-1]) swap(nums[idx-1],nums[nums[idx-1]-1]);
            idx++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};