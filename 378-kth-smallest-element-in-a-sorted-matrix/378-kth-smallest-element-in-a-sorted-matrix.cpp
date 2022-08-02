class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0],high=matrix[n-1][n-1];
        int cnt=0,i,j,ans;
        while(low<=high){
            cnt=0;
            int mid=low+(high-low)/2;
            for(i=0;i<n;i++){
                for(j=n-1;j>=0;j--){
                    if(matrix[i][j]<=mid) break; 
                }
                cnt+=j+1;
            }
            if(cnt<k) low=mid+1;
            else {ans=mid;high=mid-1;}
        }
        return ans;
    }
};