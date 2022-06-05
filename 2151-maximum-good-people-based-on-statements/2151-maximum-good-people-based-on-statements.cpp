class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) { 
        int n=statements.size();
        int cnt=0,maxx=0;
        for(int mask=0;mask<(1<<n);mask++){
            cnt=__builtin_popcount(mask);
            for(int i=0;i<=n-1;i++){
                if(mask&(1<<i)){
                    for(int j=0;j<n;j++){
                        if(statements[i][j]==1&&!(mask&(1<<j))){
                            cnt=-1;
                            break;
                        }
                        else if(statements[i][j]==0&&(mask&(1<<j))){
                            cnt=-1;
                            break;
                        }
                        else continue;
                    }
                    if(cnt==-1) break;
                }
                if(cnt==-1) break;
            }
            maxx=max(maxx,cnt);
        }
        return maxx;
    }
};