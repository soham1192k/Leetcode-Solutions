class Solution {
public:
    int row[4]={-1,0,0,1};
    int col[4]={0,-1,1,0};
    vector<int>adj[40005];
    int indegree[40005];
    vector<int>order;
    bool ok(int nr,int nc,int n,int m){
        return nr>=0&&nr<n&&nc>=0&&nc<m;
    }
    void kahn(int n){
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            order.push_back(curr);
            for(auto edge:adj[curr]){
                indegree[edge]--;
                if(indegree[edge]==0) q.push(edge);
            }
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int nr=i+row[k];
                    int nc=j+col[k];
                    if(ok(nr,nc,n,m)&&matrix[nr][nc]>matrix[i][j]) {adj[i*m+j].push_back(nr*m+nc);indegree[nr*m+nc]++;}
                }
            }
        }
        kahn(n*m);
        vector<int>dp(n*m,1);
        for(int i=0;i<order.size();i++){
            for(auto edge:adj[order[i]]) dp[edge]=max(dp[edge],1+dp[order[i]]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};