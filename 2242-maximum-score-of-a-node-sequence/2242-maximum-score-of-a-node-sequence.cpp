class Solution {
public:
    vector<pair<int,int>>adj[50005];
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n=scores.size();
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({scores[edges[i][1]],edges[i][1]});
            adj[edges[i][1]].push_back({scores[edges[i][0]],edges[i][0]});
        }
        for(int i=0;i<n;i++) sort(adj[i].rbegin(),adj[i].rend());
        int maxx=-1;
        for(int i=0;i<edges.size();i++){
            int local_maxx=-1;
            int u=edges[i][0];
            int v=edges[i][1];
            if(adj[u].size()<2||adj[v].size()<2) continue;
            int t1=-1,t2=-1;
            int curr=scores[u]+scores[v];
            if(adj[u][0].second==v){
                curr+=adj[u][1].first;
                t1=adj[u][1].second;
            }
            else{
                curr+=adj[u][0].first;
                t1=adj[u][0].second;
            }
            if(adj[v][0].second==u){
                if(adj[v][1].second==t1){
                    if(adj[v].size()>2){
                        curr+=adj[v][2].first;
                        t2=adj[v][2].second;
                    }    
                }
                else{
                    curr+=adj[v][1].first;
                    t2=adj[v][1].second;
                }
            }
            else if(adj[v][0].second==t1){
                if(adj[v][1].second==u){
                    if(adj[v].size()>2){
                        curr+=adj[v][2].first;
                        t2=adj[v][2].second;
                    }
                }
                else{
                    curr+=adj[v][1].first;
                    t2=adj[v][1].second;
                }
            }
            else{
                curr+=adj[v][0].first;
                t2=adj[v][0].second;
            }
            int t3=-1,t4=-1;
            int curr2=scores[u]+scores[v];
            if(adj[v][0].second==u){
                curr2+=adj[v][1].first;
                t3=adj[v][1].second;
            }
            else{
                curr2+=adj[v][0].first;
                t3=adj[v][0].second;
            }
            if(adj[u][0].second==v){
                if(adj[u][1].second==t3){
                    if(adj[u].size()>2){
                        curr2+=adj[u][2].first;
                        t4=adj[u][2].second;
                    }    
                }
                else{
                    curr2+=adj[u][1].first;
                    t4=adj[u][1].second;
                }
            }
            else if(adj[u][0].second==t3){
                if(adj[u][1].second==v){
                    if(adj[u].size()>2){
                        curr2+=adj[u][2].first;
                        t4=adj[u][2].second;
                    }
                }
                else{
                    curr2+=adj[u][1].first;
                    t4=adj[u][1].second;
                }
            }
            else{
                curr2+=adj[u][0].first;
                t4=adj[u][0].second;
            }
            if(t1!=-1&&t2!=-1) local_maxx=max(local_maxx,curr);
            if(t3!=-1&&t4!=-1) local_maxx=max(local_maxx,curr2);
            maxx=max(maxx,local_maxx);
        }
        return maxx;
    }
};