using ll=long long;
class Solution {
public:
    int mod=1e9+7;
    vector<pair<ll,ll>>adj[201];
    int countPaths(int n, vector<vector<int>>& roads) {
        for(ll i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<ll>d(n,1e18);
        vector<ll>cnt(n,0);
        d[0]=0;
        cnt[0]=1;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
        q.push({d[0],0});
        while(!q.empty()){
            pair<ll,ll>curr=q.top();
            q.pop();
            ll v=curr.second;
            ll d_v=curr.first;
            if(d_v!=d[v]) continue;
            for(auto edge:adj[v]){
                ll to=edge.first;
                ll len=edge.second;
                if(d[v]+len<=d[to]){
                    if(d[v]+len==d[to]){
                        cnt[to]=(cnt[to]+cnt[v])%mod;
                    }
                    else{
                        d[to]=d[v]+len;
                        q.push({d[to],to});
                        cnt[to]=cnt[v]%mod;
                    }
                }
            }
        }
        return cnt[n-1];
    }
};