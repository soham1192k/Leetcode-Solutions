class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long>arr(n,0);
        for(int i=0;i<n;i++) arr[edges[i]]+=i;
        long long idx=-1,maxx=-1;
        for(int i=0;i<n;i++){
            if(maxx<arr[i]){
                maxx=arr[i];
                idx=i;
            }
        }
        return idx;
    }
};