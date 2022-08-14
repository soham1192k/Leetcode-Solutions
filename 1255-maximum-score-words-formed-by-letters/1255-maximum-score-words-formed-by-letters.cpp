class Solution {
public:
    map<int,vector<int>>mp;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        for(int i=0;i<n;i++){
            vector<int>temp(26,0);
            for(auto y:words[i]) temp[y-'a']++;
            mp[i]=temp;
        }
        vector<int>av(26,0);
        for(auto x:letters) av[x-'a']++;
        int ans=0;
        for(int mask=0;mask<(1<<n);mask++){
            vector<int>used(26,0);
            int sc=0;
            for(int bit=0;bit<n;bit++){
                int currbit=(mask>>bit)&1;
                if(currbit){
                    for(int i=0;i<26;i++) {used[i]+=mp[bit][i];sc+=mp[bit][i]*score[i];}
                }
            }
            bool possible=true;
            for(int i=0;i<26;i++){
                if(used[i]>av[i]) {possible=false;break;}
            }
            if(possible) ans=max(ans,sc);
        }
        return ans;
    }
};