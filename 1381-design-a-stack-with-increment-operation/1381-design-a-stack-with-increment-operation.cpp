class CustomStack {
public:
    vector<int>hold;
    int maxx;
    CustomStack(int maxSize) {
        maxx=maxSize;
    }
    void push(int x) {
        if(hold.size()==maxx) ;
        else hold.push_back(x);   
    }
    int pop() {
        if(hold.empty()) return -1;
        int val=hold.back();
        hold.pop_back();   
        return val;
    }
    void increment(int k, int val) {
        for(int i=0;i<min(k,(int)hold.size());i++) hold[i]+=val;
    }
};