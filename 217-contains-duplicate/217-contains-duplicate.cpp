class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        map<int,bool>mp;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]) return true;
            mp[nums[i]]=true;
        }
        return false;
    }
};