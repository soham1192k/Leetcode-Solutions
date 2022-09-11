const int mod=1e9+7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>hold;
        for(int i=0;i<n;i++) hold.push_back({efficiency[i],speed[i]});
        sort(hold.begin(),hold.end());
        long long curr=0;
        priority_queue<int,vector<int>,greater<int>>q;
        long long maxx=0;
        for(int i=n-1;i>=0;i--){
            curr+=hold[i].second;
            q.push(hold[i].second);
            if(q.size()>k){
                curr-=q.top();
                q.pop();
            }
            maxx=max(maxx,1ll*curr*hold[i].first);
        }
        return maxx%mod;
    }
};