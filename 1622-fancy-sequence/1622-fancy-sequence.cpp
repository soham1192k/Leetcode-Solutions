class Fancy {
public:
    long long increment;
    long long mult;
    long long curr;
    const int mod=1e9+7;
    vector<int>hold;
    int pow(long long a,long long b){
        long long ans=1;
        while(b){
            if(b&1){
                ans=(ans*a)%mod;
                b--;
            }
            else{
                a=(a*a)%mod;
                b=b>>1;
            }
        }
        return ans;
    }
    int modinv(int x){
        return pow(x,mod-2);
    }
    Fancy() {
        hold.resize(100005);
        increment=curr=0;
        mult=1;
    }
    void append(int val) {
        long long temp=val;
        temp=(val-increment+mod)%mod;
        temp=(temp*modinv(mult))%mod;
        hold[curr++]=temp;
    }
    void addAll(int inc) {
        increment=(increment+inc)%mod;
    }
    void multAll(int m) {
        mult=(mult*m)%mod;
        increment=(increment*m)%mod;
    }
    int getIndex(int idx) {
        if(idx>=curr) return -1;
        int val=(hold[idx]*mult)%mod;
        return (val+increment)%mod;
    }
};
