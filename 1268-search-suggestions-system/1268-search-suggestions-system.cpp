class Solution {
public:
    vector<vector<string>>ans;
    bool comp(string&a,string&b,int n){
        for(int i=0;i<n;i++){
            if(b[i]!=a[i]) return false;
        }
        return true;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string s) {
        sort(products.begin(),products.end());
        int n=products.size();
        string prefix="";
        for(auto x:s){
            prefix+=x;
            int idx=lower_bound(products.begin(),products.end(),prefix)-products.begin();
            vector<string>temp;
            for(int i=idx;i<min(idx+3,n);i++){
                if(comp(products[i],prefix,prefix.length())) temp.push_back(products[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};