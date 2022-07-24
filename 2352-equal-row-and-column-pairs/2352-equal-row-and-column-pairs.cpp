class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string,int>mp;
        int n=grid.size();
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+='0'+grid[i][j];
                if(j<n) s+='@';
            }
            mp[s]++;
        }
        int cnt=0;
        for(int j=0;j<n;j++){
            string s="";
            for(int i=0;i<n;i++){
                s+=grid[i][j]+'0';
                if(i<n) s+='@';
            }
            cnt+=mp[s];
        }
        return cnt;
    }
};