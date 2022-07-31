class Solution {
public:
    vector<int>adj[100005];
    void bfs(int src,vector<int>&d,vector<bool>&visited){
        queue<int>q;
        q.push(src);
        d[src]=0;
        visited[src]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto edge:adj[curr]){
                if(!visited[edge]){
                    visited[edge]=true;
                    d[edge]=1+d[curr];
                    q.push(edge);
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        for(int i=0;i<n;i++){
            if(edges[i]!=-1) adj[i].push_back(edges[i]);
        }
        vector<int>d1(n,1e9),d2(n,1e9);
        vector<bool>visited(n,false);
        bfs(node1,d1,visited);
        for(int i=0;i<n;i++) visited[i]=false;
        bfs(node2,d2,visited);
        int ans=1e9+10,idx=-1;
        for(int i=0;i<n;i++){
            if(d1[i]!=1e9&&d2[i]!=1e9){
                if(ans>max(d1[i],d2[i])){
                    ans=max(d1[i],d2[i]);
                    idx=i;
                }
            }
        }
        return idx;
    }
};