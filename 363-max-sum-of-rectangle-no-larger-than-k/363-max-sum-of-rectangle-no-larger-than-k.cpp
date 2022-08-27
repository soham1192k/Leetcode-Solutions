class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(n==0||m==0) return 0;
        int pre[n][m];
        for(int i=0;i<n;i++) pre[i][0]=matrix[i][0];
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++) pre[i][j]=pre[i][j-1]+matrix[i][j];
        }
        vector<int>hold(n,0);
        int maxx=-1e9;
        for(int left=0;left<m;left++){
            for(int right=left;right<m;right++){
                for(int i=0;i<n;i++){
                    hold[i]=pre[i][right];
                    if(left-1>=0) hold[i]-=pre[i][left-1];
                }
                set<int>s;
                s.insert(0);
                int curr=0,currmaxx=-1e9;
                for(auto x:hold){
                    curr+=x;
                    auto itr=s.lower_bound(curr-k);
                    if(itr!=s.end()) currmaxx=max(currmaxx,curr-*itr);
                    s.insert(curr);
                }
                maxx=max(maxx,currmaxx);
            }
        }
        return maxx;
    }
};
