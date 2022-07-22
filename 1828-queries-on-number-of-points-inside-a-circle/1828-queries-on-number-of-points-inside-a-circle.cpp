class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<points.size();j++){
                int dist=(queries[i][0]-points[j][0])*(queries[i][0]-points[j][0]);
                dist+=(queries[i][1]-points[j][1])*(queries[i][1]-points[j][1]);
                if(dist<=queries[i][2]*queries[i][2]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};