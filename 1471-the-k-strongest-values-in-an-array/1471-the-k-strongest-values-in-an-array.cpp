class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first) return a.second>b.second;
        return a.first>b.first;
    }
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int median=arr[(n-1)/2];
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++) v[i]={abs(arr[i]-median),arr[i]};
        sort(v.begin(),v.end(),cmp);
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            ans[i]=v[i].second;
        }
        return ans;
    }
};