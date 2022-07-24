class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,j=m-1;
        while(i<n&&j>=0){
            if(target<matrix[i][j]) j--;
            else if(target>matrix[i][j]) i++;
            else return true;
        }
        return false;
    }
};