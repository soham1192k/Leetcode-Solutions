class Solution {
public:
    vector<pair<int,int>>adj[101];
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        int d[n+1];
        for(int i=1;i<=n;i++) d[i]=1e9;
        d[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({d[k],k});
        while(!q.empty()){
            pair<int,int>v=q.top();
            q.pop();
            if(d[v.second]!=v.first) continue;
            for(auto edge:adj[v.second]){
                int to=edge.first;
                int len=edge.second;
                if(d[to]>len+d[v.second]){
                    d[to]=len+d[v.second];
                    q.push({d[to],to});
                }
            }
        }
        int maxx=-1;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,d[i]);
        }
        if(maxx==1e9) return -1;
        return maxx;
    }
};