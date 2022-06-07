class Solution {
public:
    int par[100005];
    int sz[100005];
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void merge(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if (sz[a]<sz[b]) swap(a, b);
            par[b]=a;
            sz[a]+=sz[b];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        int cnt=0;
        for(int i=1;i<=n;i++) {par[i]=i;sz[i]=1;}
        for(int i=0;i<connections.size();i++){
            int a=find(connections[i][0]);
            int b=find(connections[i][1]);
            if(a!=b){
                cnt++;
                merge(connections[i][0],connections[i][1]);
            }
        }
        return n-1-cnt;
    }
};