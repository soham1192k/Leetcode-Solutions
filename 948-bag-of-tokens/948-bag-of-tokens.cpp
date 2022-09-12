class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int left=0,right=n-1;
        int score=0,maxx=0;
        bool flag=true;
        while(left<=right&&flag){
            flag=false;
            while(left<=right&&power>=tokens[left]){
                score++;
                power-=tokens[left++];
                flag=true;
            }
            maxx=max(maxx,score);
            if(right>=left&&score>=1){
                power+=tokens[right--];
                score--;
                flag=true;
            }
        }
        return maxx;
    }
};