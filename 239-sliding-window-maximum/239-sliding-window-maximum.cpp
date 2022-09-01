class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>s;
        int n=nums.size();
        for(int i=0;i<k;i++) s.insert(nums[i]);
        vector<int>ans;
        auto itr=s.end();
        itr--;
        ans.push_back(*itr);
        for(int i=k;i<n;i++){
            s.erase(s.find(nums[i-k]));
            s.insert(nums[i]);
            itr=s.end();
            itr--;
            ans.push_back(*itr);
        }
        return ans;
    }
};