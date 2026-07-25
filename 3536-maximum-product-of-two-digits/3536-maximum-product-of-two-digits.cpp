class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;
        while(n>0){
            v.push_back(n%10);
            n/=10;
        }
        sort(v.begin(),v.end());
        return v[v.size()-1]*v[v.size()-2];
    }
};