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

// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {
//         int mod = 1e9+7;
//         vector<vector<pair<int, int>>> graph(n);
//         for(auto &road: roads) {
//             graph[road[0]].push_back({road[1], road[2]});
//             graph[road[1]].push_back({road[0], road[2]});
//         }
        
//         vector<long long> distance(n, LONG_MAX);
//         vector<int> path(n, 0);
        
//         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
//         pq.push({0, 0});
//         distance[0] = 0;
//         path[0] = 1;
        
//         while(!pq.empty()) {
//             pair<long long, int> t = pq.top();
//             pq.pop();
            
//             for(auto &nbr: graph[t.second]) {
//                 long long vert = nbr.first;
//                 long long edge = nbr.second;
                
//                 if(distance[vert] > distance[t.second] + edge) {
//                     distance[vert] = distance[t.second] + edge;
//                     pq.push({distance[vert], vert});
//                     path[vert] = path[t.second] %mod;
//                 }
//                 else if(distance[vert] == t.first + edge) {
//                     path[vert] += path[t.second];
//                     path[vert] %= mod;
//                 }
//             }
//         }
        
//         return path[n-1];
//     }
// };