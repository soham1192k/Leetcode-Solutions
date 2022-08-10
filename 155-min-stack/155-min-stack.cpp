class MinStack {
public:
    stack<pair<int,int>>st;
    int currmin;
    MinStack() {
        currmin=INT_MAX;
    }
    void push(int val) {
        st.push({val,min(currmin,val)});
        currmin=min(currmin,val);
    }
    void pop() {
        st.pop();
        if(st.empty()) currmin=INT_MAX; 
        else currmin=st.top().second;
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
};