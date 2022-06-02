class Solution {
public:
    bool ok(vector<int>&bloomDay,int n,int m,int k,int mid){
        int cnt=0;int done=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid) cnt++;
            else cnt=0;
            if(cnt==k){
                cnt=0;done++;
            }
        }
        return done>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m*k>n) return -1;
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ok(bloomDay,n,m,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};