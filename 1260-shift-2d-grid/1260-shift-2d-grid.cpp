class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        k%=(n*m);
        int times=k/m;
        k%=m;
        for(int i=1;i<=times;i++){
            vector<int>hold=grid[n-1];
            for(int j=n-2;j>=0;j--){
                grid[j+1]=grid[j];
            }
            grid[0]=hold;
        }
        for(int i=1;i<=k;i++){
            int temp=grid[n-1][m-1];
            for(int j=n-1;j>=0;j--){
                for(int k=m-1;k>=1;k--) grid[j][k]=grid[j][k-1];
                if(j-1>=0) grid[j][0]=grid[j-1][m-1];
            }
            grid[0][0]=temp;
        }
        return grid;
    }
};