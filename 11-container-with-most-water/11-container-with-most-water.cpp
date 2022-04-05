class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int maxx=-1;
        while(i<j){
            maxx=max(maxx,min(height[i],height[j])*(j-i));         
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxx;
    }
};