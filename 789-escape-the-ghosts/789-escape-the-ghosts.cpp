class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int n=ghosts.size();
        int minn=1e9;
        for(auto x:ghosts) minn=min(minn,abs(target[0]-x[0])+abs(target[1]-x[1]));
        if(minn<=abs(target[0]-0)+abs(target[1]-0)) return false;
        return true;
    }
};