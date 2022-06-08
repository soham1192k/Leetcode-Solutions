class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int arr1[n],arr2[n];
        for(int i=0;i<n;i++){
            arr1[i]=i+values[i];
            arr2[i]=values[i]-i;
        }
        int suff[n];
        suff[n-1]=-1e9;
        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1],arr2[i+1]);
        }
        int maxx=0;
        for(int i=0;i<n;i++){
            maxx=max(maxx,arr1[i]+suff[i]);
        }
        return maxx;
    }
};

