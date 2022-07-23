class Solution {
public:
    int compute(int x){
        if(x==1) return 0;
        int ans=0;
        if(x%2) ans=1+compute(3*x+1);
        else ans=1+compute(x/2);
        return ans;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>hold;
        for(int i=lo;i<=hi;i++) hold.push_back({compute(i),i});
        sort(hold.begin(),hold.end());
        return hold[k-1].second;
    }
};


