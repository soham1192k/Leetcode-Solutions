class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int dp[n][n][n];
        dp[0][0][0]=grid[0][0];
        for(int r1=0;r1<n;r1++){
            for(int c1=0;c1<n;c1++){
                for(int c2=0;c2<n;c2++){
                    int r2=r1+c1-c2;
                    if(r2<0||r2>=n) continue;
                    dp[r1][c1][c2]=-1e9;
                    if(r1==0&&c2==0&&c1==0) {dp[r1][c1][c2]=grid[0][0];continue;}
                    if(grid[r1][c1]==-1||grid[r2][c2]==-1) continue;
                    else{
                        dp[r1][c1][c2]=-1e9;
                        if(r1==r2&&c1==c2){
                            // p1 down,p2 down
                            if(r1-1>=0&&r2-1>=0&&grid[r1-1][c1]!=-1&&grid[r2-1][c2]!=-1) dp[r1][c1][c2]=max(dp[r1][c1][c2],grid[r1][c1]+dp[r1-1][c1][c2]);
                            // p1 down,p2 right
                            if(r1-1>=0&&c2-1>=0&&grid[r1-1][c1]!=-1&&grid[r2][c2-1]!=-1) dp[r1][c1][c2]=max(dp[r1][c1][c2],grid[r1][c1]+dp[r1-1][c1][c2-1]);
                            // p1 right,p2 down
                            if(c1-1>=0&&r2-1>=0&&grid[r1][c1-1]!=-1&&grid[r2-1][c2]!=-1) dp[r1][c1][c2]=max(dp[r1][c1][c2],grid[r1][c1]+dp[r1][c1-1][c2]);
                            // p1 right,p2 right
                            if(c1-1>=0&&c2-1>=0&&grid[r1][c1-1]!=-1&&grid[r2][c2-1]!=-1) dp[r1][c1][c2]=max(dp[r1][c1][c2],grid[r1][c1]+dp[r1][c1-1][c2-1]);
                        }
                        else{
                            //p1 down,p2 down
                            if(r1-1>=0&&r2-1>=0&&grid[r1-1][c1]!=-1&&grid[r2-1][c2]!=-1) dp[r1][c1][c2]=max(dp[r1][c1][c2],grid[r1][c1]+grid[r2][c2]+dp[r1-1][c1][c2]);
                            //p1 down,p2 right
                            if(r1-1>=0&&c2-1>=0&&grid[r1-1][c1]!=-1&&grid[r2][c2-1]!=-1) dp[r1][c1][c2]=max(dp[r1][c1][c2],grid[r1][c1]+grid[r2][c2]+dp[r1-1][c1][c2-1]);
                            //p1 right,p2 down
                            if(c1-1>=0&&r2-1>=0&&grid[r1][c1-1]!=-1&&grid[r2-1][c2]!=-1) dp[r1][c1][c2]=max(dp[r1][c1][c2],grid[r1][c1]+grid[r2][c2]+dp[r1][c1-1][c2]);
                            //p1 right,p2 right
                            if(c1-1>=0&&c2-1>=0&&grid[r1][c1-1]!=-1&&grid[r2][c2-1]!=-1) dp[r1][c1][c2]=max(dp[r1][c1][c2],grid[r1][c1]+grid[r2][c2]+dp[r1][c1-1][c2-1]);
                        }
                    }
                }
            }
        }
        if(dp[n-1][n-1][n-1]<=0) return 0;
        return dp[n-1][n-1][n-1];
    }
};