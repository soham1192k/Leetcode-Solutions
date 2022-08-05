class Solution {
public:
    int stoneGameVI(vector<int>&a, vector<int>&b) {
        int n=a.size();
        vector<pair<int,int>>hold(n);
        for(int i=0;i<n;i++) hold[i]={a[i]+b[i],i};
        sort(hold.rbegin(),hold.rend());
        int alice=0,bob=0;
        for(int i=0;i<n;i++){
            if(i%2==0) alice+=a[hold[i].second];
            else bob+=b[hold[i].second];
        }
        if(alice>bob) return 1;
        else if(alice==bob) return 0;
        return -1;
    }
};