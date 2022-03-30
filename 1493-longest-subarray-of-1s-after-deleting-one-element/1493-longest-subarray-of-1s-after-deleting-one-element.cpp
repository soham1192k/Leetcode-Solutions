class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int left[n],right[n];
        left[0]=0;right[n-1]=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]==1) left[i]=left[i-1]+1;
            else left[i]=0;
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]==1) right[i]=right[i+1]+1;
            else right[i]=0;
        }
        int maxx=0;
        for(int i=0;i<n;i++) maxx=max(maxx,left[i]+right[i]);
        return maxx;
    }
};