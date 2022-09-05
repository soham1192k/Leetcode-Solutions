class Solution {
public:
    bool parseBoolExpr(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]==',') continue;
            else if(s[i]==')'){
                vector<char>hold;
                while(!st.empty()){
                    char ch=st.top();
                    st.pop();
                    if(ch=='t'||ch=='f') hold.push_back(ch);
                    else if(ch=='(') break;
                }
                char op=st.top();
                st.pop();
                if(op=='&'){
                    bool flag=true;
                    for(auto x:hold){
                        if(x=='f') {flag=false;break;}
                    }
                    if(flag) st.push('t');
                    else st.push('f');
                }
                else if(op=='|'){
                    bool flag=false;
                    for(auto x:hold){
                        if(x=='t') {flag=true;break;}
                    }
                    if(flag) st.push('t');
                    else st.push('f');
                }
                else if(op=='!'){
                    if(hold[0]=='t') st.push('f');
                    else st.push('t');
                }
            }
            else st.push(s[i]);
        }
        return st.top()=='t';
    }
};