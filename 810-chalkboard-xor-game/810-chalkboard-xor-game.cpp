class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int val=0;
        for(auto x:nums) val^=x;
        if(!val||nums.size()%2==0) return true;
        return false;
    }
};