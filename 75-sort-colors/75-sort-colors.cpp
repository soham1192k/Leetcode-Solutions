class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return ;
        int low=0,mid=0;
        int high=n-1;
        while(mid<=high){
            if(low<0||mid>=n) break;
            if(nums[mid]==0){
                swap(nums[mid++],nums[low++]);
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high--]);
            }
            if(mid<n&&nums[mid]==1) mid++;
        }
    }
};