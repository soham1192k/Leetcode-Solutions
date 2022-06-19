class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        int u=0,l=0,r=n-1,d=m-1;
        
        int ct=m*n;
        vector<int> ans;
        while(l<=r && u<=d)
        {
            for(int j=l;j<=r;j++)
            {
                ans.push_back(mat[u][j]);
            }
            u++;
            if(u>d) break;
            for(int i=u;i<=d;i++)
            {
                ans.push_back(mat[i][r]);
            }
            r--;
            if(l>r) break;
            for(int j=r;j>=l;j--)
            {
                ans.push_back(mat[d][j]);
            }
            d--;
            if(u>d) break;
            for(int i=d;i>=u;i--)
            {
                ans.push_back(mat[i][l]);
            }
            l++;
        }
        
        return ans;
    }
};