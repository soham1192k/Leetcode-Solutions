class Solution {
public:
    int par[1001];
    int sz[1001];
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(sz[a]<sz[b]) swap(a,b);
            par[b]=a;
            sz[a]+=sz[b];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        for(int i=1;i<=n;i++) {par[i]=i;sz[i]=1;}
        for(int i=0;i<n;i++){
            int a=find(edges[i][0]);
            int b=find(edges[i][1]);
            if(a==b) return {edges[i][0],edges[i][1]};
            else merge(edges[i][0],edges[i][1]);
        }
        return {};
    }
};