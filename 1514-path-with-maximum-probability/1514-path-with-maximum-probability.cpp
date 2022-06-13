class Solution {
public:
    double eps=1e-6;
    vector<pair<int,double>>adj[10005];
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>d(n,0.0);
        d[start]=1.0;
        priority_queue<pair<double,int>>q;
        q.push({d[start],start});
        while(!q.empty()){
            pair<double,int>curr=q.top();
            q.pop();
            double d_v=curr.first;
            int v=curr.second;
            if(abs(d_v-d[v])>eps) continue;
            for(auto edge:adj[v]){
                int to=edge.first;
                double len=edge.second;
                if(d[to]<d[v]*len){
                    d[to]=d[v]*len;
                    q.push({d[to],to});
                }
            }
        }
        return d[end];
    }
};