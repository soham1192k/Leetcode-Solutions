class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.length();
        int minn=0; 
        int t=0,f=0;
        if(answerKey[0]=='T') t++;
        else f++;
        int left=0,right=1;
        int maxlen=1;
        while(right<n){
            if(answerKey[right]=='T') t++;
            else f++;
            minn=min(t,f);
            if(minn<=k){
                maxlen=max(maxlen,right-left+1);
            }
            else{
                while(left<=right&&minn>k){
                    if(answerKey[left]=='T') t--;
                    else f--;
                    minn=min(t,f);
                    left++;
                    maxlen=max(maxlen,right-left+1);
                }
            }
            right++;
        }
        return maxlen;
    }
};