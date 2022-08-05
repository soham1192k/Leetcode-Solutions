class Solution {
public:
    int cnt;
    int maxx;
    void func(vector<int>&nums,int idx,int mask){
        if(idx<0){
            int val=0;
            for(int i=0;i<nums.size();i++){
                if(mask&(1<<i)) val|=nums[i]; 
            } 
            if(maxx<=val){
                if(maxx==val) cnt++;
                else {cnt=1;maxx=val;}
            }
            return;
        }
        func(nums,idx-1,mask);
        int n_mask=mask|(1<<idx);
        func(nums,idx-1,n_mask);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        func(nums,n-1,0);
        return cnt;
    }
};