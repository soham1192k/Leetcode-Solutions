class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int curr=nums[0];
        for(int i=1;i<n;i++){
            if(i>curr) return false;
            curr=max(curr,i+nums[i]);
        }
        return true;
    }
};