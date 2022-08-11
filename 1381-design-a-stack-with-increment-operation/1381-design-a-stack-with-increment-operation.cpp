class CustomStack {
public:
    vector<int>hold,inc;
    int maxx;
    CustomStack(int maxSize) {
        maxx=maxSize;
    }
    void push(int x) {
        if(hold.size()==maxx) return;
        hold.push_back(x);
        inc.push_back(0);
    }
    int pop() {
        if(hold.empty()) return -1;
        int idx=hold.size()-1;
        if(idx>0) inc[idx-1]+=inc[idx];
        int val=hold.back()+inc.back();
        hold.pop_back();
        inc.pop_back();
        return val;
    }
    void increment(int k, int val) {
        int q=min(k-1,(int)hold.size()-1);
        if(q>=0) inc[q]+=val;
    }
};