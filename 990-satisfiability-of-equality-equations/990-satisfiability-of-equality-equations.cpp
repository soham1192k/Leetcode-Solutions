class Solution {
public:
    map<char,char>par;
    map<char,int>sz;
    char find(char x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void merge(char a,char b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(sz[a]<sz[b]) swap(a,b);
            par[b]=a;
            sz[a]+=sz[b];
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        for(char ch='a';ch<='z';ch++){
            par[ch]=ch;
            sz[ch]=1;
        }
        for(int i=0;i<n;i++){
            if(equations[i][1]=='='){
                char ch1=find(equations[i][0]);
                char ch2=find(equations[i][3]);
                merge(ch1,ch2);
            }
        }
        for(int i=0;i<n;i++){
            if(equations[i][1]=='!'){
                char ch1=find(equations[i][0]);
                char ch2=find(equations[i][3]);
                if(ch1==ch2) return false;
            }
        }
        return true;
    }
};