class Solution {
public:
    vector<pair<int,int>>adj[100005];
    vector<pair<int,int>>adj_r[100005];
    const long long INF=1e18;
    void dijkstra(int n,int s, vector<long long>&d,bool rev=false) {
        d.assign(n, INF);
        d[s] = 0;
        set<pair<int, int>> q;
        q.insert({0, s});
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());
            if(rev){
                for (auto edge : adj_r[v]) {
                    int to = edge.first;
                    int len = edge.second;
                    if (d[v] + len < d[to]) {
                        q.erase({d[to], to});
                        d[to] = d[v] + len;
                        q.insert({d[to], to});
                    }
                }
            }
            else{
                for (auto edge : adj[v]) {
                    int to = edge.first;
                    int len = edge.second;
                    if (d[v] + len < d[to]) {
                        q.erase({d[to], to});
                        d[to] = d[v] + len;
                        q.insert({d[to], to});
                    }
                }
            }
            
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj_r[x[1]].push_back({x[0],x[2]});
        }
        vector<long long>d_src1,d_src2,d_dest;
        dijkstra(n,src1,d_src1);
        dijkstra(n,src2,d_src2);
        dijkstra(n,dest,d_dest,true);
        long long minn=1e18;
        for(int i=0;i<n;i++) minn=min(minn,d_src1[i]+d_src2[i]+d_dest[i]);
        if(minn==1e18) return -1;
        return minn;
    }
};