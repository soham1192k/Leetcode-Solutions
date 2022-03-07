class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0,j=0;
        if(n==1&&nums[0]==val) return 0;
        else if(n==1) return 1;
        while(j<n){
            if(nums[j]==val) j++;
            else{
                swap(nums[i++],nums[j++]);
            }
        }
        return i;
    }
};