class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int j=n-1;
        while(j>0&&nums[j-1]>=nums[j]) j--;
        if(j>0){
            int ptr=n-1;
            while(ptr>=0&&nums[ptr]<=nums[j-1]) ptr--;
            swap(nums[ptr],nums[j-1]);
            reverse(nums.begin()+j,nums.end());
        } 
        else reverse(nums.begin(),nums.end());
    }
};


