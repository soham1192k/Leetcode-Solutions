class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n=grades.size();
        for(int i=1;;i++){
            if(i*(i+1)==2*n) return i;
            else if(i*(i+1)>2*n) return i-1;
        }
        return 1;
    }
};

