class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        map<int,int>loss;
        set<int>played;
        for(int i=0;i<n;i++) {played.insert(matches[i][0]);played.insert(matches[i][1]);loss[matches[i][1]]++;}
        vector<vector<int>>ans;
        vector<int>temp,temp1;
        for(auto x:played){
            if(loss[x]==0) temp.push_back(x);
            if(loss[x]==1) temp1.push_back(x);
        }
        sort(temp.begin(),temp.end());
        sort(temp1.begin(),temp1.end());
        ans.push_back(temp);
        ans.push_back(temp1);
        return ans;
    }
};