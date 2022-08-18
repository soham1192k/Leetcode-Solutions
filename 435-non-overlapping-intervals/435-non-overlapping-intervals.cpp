class Solution {
public:
    bool overlap(pair<int,int>&a,pair<int,int>&b){
        if(a.first<=b.first&&a.second>=b.second) return true;
        if(b.first<=a.first&&b.second>=a.second) return true;
        if(a.first<b.first&&b.first<a.second) return true;
        if(a.first<b.second&&b.second<a.second) return true;
        if(b.first<a.first&&a.first<b.second) return true;
        if(b.first<a.second&a.second<b.second) return true;
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int minn=intervals[0][0];
        int maxx=intervals[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            pair<int,int>curr={minn,maxx};
            pair<int,int>curr1={intervals[i][0],intervals[i][1]};
            if(overlap(curr,curr1)){
                cnt++;
                if(intervals[i][1]<maxx){
                    maxx=intervals[i][1];
                    minn=intervals[i][0];
                }
            }
            else{
                minn=intervals[i][0];
                maxx=intervals[i][1];
            }
        }   
        return cnt;
    }
};