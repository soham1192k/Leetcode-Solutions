using ll=long long;
class Solution {
public:
    map<ll,bool>mp;
    ll func(ll x){
        ll sum=0;
        while(x!=0){
            sum+=(x%10)*(x%10);
            x/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if(n==1) return true;
        ll val=func(n);
        mp[val]=true;
        while(val!=1){
            val=func(val);
            if(val!=1&&mp[val]) return false;
            mp[val]=true;
        }
        if(val==1) return true;
        return false;
    }
};