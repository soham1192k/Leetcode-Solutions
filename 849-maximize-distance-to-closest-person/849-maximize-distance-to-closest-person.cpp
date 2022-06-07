class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int>gaps;
        int curr=0;
        int fi=-1,li=-1;
        for(int i=0;i<n;i++){
            if(seats[i]==1) {fi=i;break;}
        }
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1) {li=i;break;}
        }
        for(int i=fi;i<=li;i++){
            if(seats[i]==0) curr++;
            else{
                gaps.push_back(curr+1);
                curr=0;
            }
        }
        sort(gaps.rbegin(),gaps.rend());
        return max({fi,n-1-li,gaps[0]/2});
    }
};