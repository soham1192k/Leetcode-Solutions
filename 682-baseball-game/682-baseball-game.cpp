class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>st;
        for(auto x:ops){
            if(x=="+"){
                int t1=st.top();
                st.pop();
                int val=t1+st.top();
                st.push(t1);
                st.push(val);
            }
            else if(x=="D") st.push(2*st.top());
            else if(x=="C") st.pop();
            else st.push(stoi(x));
        }
        int ans=0;
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};