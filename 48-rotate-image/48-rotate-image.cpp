class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int i,j;
        for(i=0,j=n-1;i<j;i++,j--) swap(matrix[i],matrix[j]);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) swap(matrix[i][j],matrix[j][i]);
        }
    }
};