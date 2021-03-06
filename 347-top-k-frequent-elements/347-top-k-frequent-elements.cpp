class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n) return nums;
        unordered_map<int,int>mp;
        for(auto x:nums) mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto x:mp){
            if(q.size()<k) q.push({x.second,x.first});
            else{
                if(q.top().first<x.second){
                    q.pop();
                    q.push({x.second,x.first});
                }
            }
        }
        nums.clear();
        for(int i=1;i<=k;i++){
            nums.push_back(q.top().second);
            q.pop();
        }
        return nums;
    }
};