class Solution {
public:
    int par[1001],sz[1001];
    int find(int x){
        if(x==par[x]) return x;
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                v.push_back({dist,{i,j}});
            }
        }
        sort(v.begin(),v.end());
        memset(par,-1,sizeof(par));
        for(int i=0;i<n;i++) {par[i]=i;sz[i]=1;}
        int cnt=0;
        for(int i=0;i<v.size();i++){
            int a=find(v[i].second.first);
            int b=find(v[i].second.second);
            if(a!=b){
                cnt+=v[i].first;
                merge(v[i].second.first,v[i].second.second);
            }
        }
        return cnt;
    }
};