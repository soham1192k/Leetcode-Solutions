class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        if(!n||!m) return {};
        int i,j,k,ptr;
        vector<int>hold;
        for(i=n-1;i>=1;i--){
            j=0;k=i;
            hold.clear();
            while(k<n&&j<m) hold.push_back(mat[k++][j++]);
            j=0;k=i;
            sort(hold.begin(),hold.end());
            ptr=0;
            while(k<n&&j<m) mat[k++][j++]=hold[ptr++];
        }
        for(j=0;j<m;j++){
            i=0;k=j;
            hold.clear();
            while(i<n&&k<m) hold.push_back(mat[i++][k++]);
            sort(hold.begin(),hold.end());
            i=0;k=j;
            ptr=0;
            while(i<n&&k<m) mat[i++][k++]=hold[ptr++];
        }
        return mat;
    }
};