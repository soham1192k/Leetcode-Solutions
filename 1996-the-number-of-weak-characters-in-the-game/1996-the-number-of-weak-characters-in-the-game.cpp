class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
        sort(properties.begin(),properties.end());
        int curr=0,cnt=0,newcurr=0;
        int idx=n-1;
        while(idx>=0){
            int now=properties[idx][0];
            while(idx>=0&&properties[idx][0]==now){
                if(properties[idx][1]<curr) cnt++;
                newcurr=max(newcurr,properties[idx][1]);
                idx--;
            }
            curr=newcurr;
        }
        return cnt;
    }
};



