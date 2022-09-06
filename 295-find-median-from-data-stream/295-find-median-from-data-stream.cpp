class MedianFinder {
public:
    priority_queue<int>maxx;
    priority_queue<int,vector<int>,greater<int>>minn;
    MedianFinder(){}
    void addNum(int num) {
        if(maxx.empty()) {maxx.push(num);return;}
        if(num<maxx.top()) maxx.push(num);
        else minn.push(num);
        if(minn.size()>1+maxx.size()){
            maxx.push(minn.top());
            minn.pop();
        }
        else if(maxx.size()>1+minn.size()){
            minn.push(maxx.top());
            maxx.pop();
        }
    }
    double findMedian() {
        if((minn.size()+maxx.size())&1){
            if(minn.size()>maxx.size()) return 1.0*minn.top();
            return 1.0*maxx.top();
        }
        return (minn.top()+maxx.top())/2.0;
    }
};