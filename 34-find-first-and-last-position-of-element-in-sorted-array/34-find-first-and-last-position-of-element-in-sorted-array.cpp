class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        if(nums.size()==0) return {-1,-1};
        auto itr=lower_bound(nums.begin(),nums.end(),target);
        if(itr==nums.end()||*itr!=target) ans.push_back(-1);
        else ans.push_back(itr-nums.begin());
        itr=upper_bound(nums.begin(),nums.end(),target);
        if(itr==nums.begin()) ans.push_back(-1);
        else{
            itr--;
            if(*itr!=target) ans.push_back(-1);
            else ans.push_back(itr-nums.begin());
        }
        return ans;
    }
};