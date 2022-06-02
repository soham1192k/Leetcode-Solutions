class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>hold;
        for(int i=0;i<n;i++) hold.push_back(envelopes[i][1]);
        vector<int>d(n+1,1e9);
        d[0]=-1e9;
        for(int i=0;i<n;i++){
            int j=upper_bound(d.begin(),d.end(),hold[i])-d.begin();
            if(d[j-1]<hold[i]&&hold[i]<d[j]) d[j]=hold[i];
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            if(d[i]<1e9) ans=i;
        }
        return ans;
    }
};