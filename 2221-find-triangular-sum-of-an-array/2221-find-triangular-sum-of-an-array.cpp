class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<=n-1;i++){
            vector<int>tmp;
            for(int j=1;j<(int)nums.size();j++){
                tmp.push_back((nums[j-1]+nums[j])%10);
            }
            nums=tmp;
        }
        return nums[0];
    }
};