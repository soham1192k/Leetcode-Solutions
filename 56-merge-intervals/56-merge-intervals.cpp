class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int maxend=intervals[0][1];
        int currstart=intervals[0][0];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=maxend) maxend=max(maxend,intervals[i][1]);
            else{
                vector<int>tmp={currstart,maxend};
                ans.push_back(tmp);
                currstart=intervals[i][0];
                maxend=intervals[i][1];
            }
        }
        vector<int>tmp={currstart,maxend};
        ans.push_back(tmp);
        return ans;
    }
};