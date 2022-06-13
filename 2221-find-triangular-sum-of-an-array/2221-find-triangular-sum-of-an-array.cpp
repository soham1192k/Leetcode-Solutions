class Solution {
public:
    int ncr[1001][1001];
    int triangularSum(vector<int>& nums) {
        for (int n=1;n<=nums.size();++n){
            for (int r=0;r<=n;++r){
                if(r==0) ncr[n][0]=1;
                else{
                    ncr[n][r]=(ncr[n-1][r-1]+ncr[n-1][r])%10;
                }
            }
        } 
        int sum=0;
        for(int i=0;i<=nums.size()-1;i++){
            int val=(nums[i]*ncr[nums.size()][i])%10;
            sum=(sum+val)%10;
        }
        return sum;
    }
};

