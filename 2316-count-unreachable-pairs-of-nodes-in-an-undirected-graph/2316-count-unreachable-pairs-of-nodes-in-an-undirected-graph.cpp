class Solution {
public:
    vector<int>adj[100005];
    vector<int>id;
    bool visited[100005];
    int cnt;
    void dfs(int src){
        visited[src]=true;
        id[src]=cnt;
        for(auto edge:adj[src]){
            if(!visited[edge]) dfs(edge);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        id.resize(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i);
            }
        }
        map<int,int>mp;
        for(int i=0;i<n;i++) mp[id[i]]++;
        vector<long long>hold;
        for(auto x:mp) hold.push_back(x.second);
        vector<long long>suff((int)hold.size());
        long long ans=0;
        suff[hold.size()-1]=hold[hold.size()-1];
        for(int i=hold.size()-2;i>=1;i--) suff[i]=hold[i]+suff[i+1];
        for(int i=0;i<hold.size()-1;i++){
            ans+=hold[i]*suff[i+1];
        }
        return ans;
    }
};