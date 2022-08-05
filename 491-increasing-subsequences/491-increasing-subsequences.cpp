class Solution {
public:
    set<vector<int>>ans;
    void func(vector<int>&a,int idx,int n,vector<int>&hold){
        if(idx==n){
            if(hold.size()>=2) ans.insert(hold);
            return;
        }
        func(a,idx+1,n,hold);
        if(hold.size()==0||hold.back()<=a[idx]){
            hold.push_back(a[idx]);
            func(a,idx+1,n,hold);
            hold.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<int>hold;
        func(nums,0,n,hold);
        vector<vector<int>>p;
        for(auto x:ans) p.push_back(x);
        return p;
    }
};