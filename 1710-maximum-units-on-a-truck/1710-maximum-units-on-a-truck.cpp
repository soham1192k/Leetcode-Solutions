class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[1]==b[1]) return a[0]>b[0];
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=boxTypes[i][1]*min(truckSize,boxTypes[i][0]);
            truckSize-=min(truckSize,boxTypes[i][0]);
            if(truckSize<=0) break;
        }
        return ans;
    }
};