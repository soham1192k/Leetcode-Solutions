class Solution {
public:
    using ll=long long;
    map<int,bool>mp;
    ll digsum(ll x){
        ll sum=0;
        while(x>0){
            int d=x%10;
            sum+=d*d;
            x/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        ll s=0;
        while(n!=1){
            s=digsum(n);
            n=s;
            if(mp[n]&&n!=1) return false; 
            mp[n]=true;
        }
        if(n==1) return true;
        return false;
    }
};