class Solution {
public:
    vector<vector<int>>ans;
    void func(vector<int>&a,int target,int idx,vector<int>&curr){
        if(idx<0){
            if(target==0){
                ans.push_back(curr);
            }
            return;
        }
        if(target<0) return;
        func(a,target,idx-1,curr);
        curr.push_back(a[idx]);
        func(a,target-a[idx],idx,curr);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>curr;
        func(candidates,target,n-1,curr);
        return ans;
    }
};