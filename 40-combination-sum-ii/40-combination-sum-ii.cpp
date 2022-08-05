class Solution {
public:
    vector<vector<int>>ans;
    map<int,int>mp;
    void func(vector<int>&a,int target,int idx,vector<int>&curr){
        if(idx<0){
            if(target==0) ans.push_back(curr);
            return;
        }
        func(a,target,idx-1,curr);
        if(mp[a[idx]]>=1&&target-a[idx]>=0){
            int val=a[idx];
            curr.push_back(val);
            mp[val]--;
            func(a,target-val,idx,curr);
            mp[val]++;
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for(auto x:candidates) mp[x]++;
        set<int>s;
        for(auto x:candidates) s.insert(x);
        candidates.clear();
        for(auto x:s) candidates.push_back(x);
        int n=candidates.size();
        vector<int>temp;
        func(candidates,target,n-1,temp);
        return ans;
    }
};