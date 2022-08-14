class Solution {
public:
    map<string,vector<string>>adj;
    bool neighbour(string&s,string&t){
        if(s.length()!=t.length()) return false;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]) cnt++;
        }
        if(cnt<=1) return true;
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        bool present_begin=false,present_end=false;
        for(int i=0;i<n;i++){
            if(wordList[i]==beginWord) present_begin=true;
            if(wordList[i]==endWord) present_end=true;
        }
        if(!present_end) return 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(neighbour(wordList[i],wordList[j])){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
            if(!present_begin&&neighbour(wordList[i],beginWord)){
                adj[beginWord].push_back(wordList[i]);
                adj[wordList[i]].push_back(beginWord);
            }
        }
        map<string,bool>visited;
        map<string,int>d;
        queue<string>q;
        q.push(beginWord);
        visited[beginWord]=true;
        d[beginWord]=0;
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            for(auto edge:adj[curr]){
                if(!visited[edge]){
                    visited[edge]=true;
                    q.push(edge);
                    d[edge]=1+d[curr];
                }
            }
        }
        if(d[endWord]==0) return 0;
        return d[endWord]+1;
    }
};