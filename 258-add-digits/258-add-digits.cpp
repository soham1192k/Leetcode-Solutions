class Solution {
public:
    int helper(int n){
        int sum=0;
        while(n!=0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int addDigits(int num) {
        while(num>=10) num=helper(num);
        return num;
    }
};