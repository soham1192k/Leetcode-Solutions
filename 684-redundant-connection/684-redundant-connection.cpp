class Solution {
public:
    int par[1001],sz[1001];
    int find_set(int x){
        if(x==par[x]) return x;
        return par[x]=find_set(par[x]);
    }
    void merge(int a,int b){
        a=find_set(a);
        b=find_set(b);
        if(a!=b){
            if(sz[a]<sz[b]) swap(a,b);
            par[b]=a;
            sz[a]+=sz[b];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        for(int i=1;i<=n;i++){
            par[i]=i;
            sz[i]=1;
        } 
        for(auto x:edges){
            int a=find_set(x[0]);
            int b=find_set(x[1]);
            if(a!=b) merge(x[0],x[1]);
            else return {x[0],x[1]};
        }
        return {};
    }
};