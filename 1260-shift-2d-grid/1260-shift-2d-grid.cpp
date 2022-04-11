class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>res(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int col=(j+k)%m;
                int wrap=(j+k)/m;
                int row=(i+wrap)%n;
                res[row][col]=grid[i][j];
            }
        }
        return res;
    }
};


