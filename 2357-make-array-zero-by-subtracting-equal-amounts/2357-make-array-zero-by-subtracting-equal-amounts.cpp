class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0,sub=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]-sub>0){
                cnt++;
                sub=nums[i];
            }
        }
        return cnt;
    }
};