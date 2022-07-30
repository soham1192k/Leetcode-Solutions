using pii=pair<pair<int,int>,pair<int,int>>;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        map<pii,int>mp;
        int g;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int slope_num,slope_den,intercept_num,intercept_den;
                slope_num=points[i][1]-points[j][1];
                slope_den=points[i][0]-points[j][0];
                intercept_num=-points[j][0]*slope_num+points[j][1]*slope_den;
                intercept_den=slope_den;
                g=__gcd(slope_num,slope_den);
                if(slope_den!=0&&g) {slope_num/=g;slope_den/=g;}
                g=__gcd(intercept_num,intercept_den);
                if(intercept_den!=0&&g) {intercept_num/=g;intercept_den/=g;}
                if(slope_den==0) mp[{{0,0},{points[i][0],0}}]++;
                else mp[{{slope_num,slope_den},{intercept_num,intercept_den}}]++;
            }
        }
        int maxx=0;
        for(auto x:mp) maxx=max(maxx,x.second);
        int ans=1;
        for(int i=2;i<=points.size();i++){
            if(i*(i-1)==2*maxx) ans=i;
        }
        return ans;
    }
};