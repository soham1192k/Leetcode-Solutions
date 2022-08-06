class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        double val=log10(buckets)/log10(1+(minutesToTest/minutesToDie));
        val=ceil(val);
        return (int)val;
    }
};


