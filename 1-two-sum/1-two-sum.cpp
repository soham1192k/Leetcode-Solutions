class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp[target-nums[i]]!=0){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]-1);
            }
            mp[nums[i]]=i+1;
        }
        return ans;
    }
};