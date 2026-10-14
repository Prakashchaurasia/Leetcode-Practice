class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n=rectangles.size();
        unordered_map<double,long long> mp;
        for(int i=0;i<n;i++){
            double x=rectangles[i][0];
            double y=rectangles[i][1];
            mp[x/y]++;
        }
        long long ans=0;
        for(auto ele:mp){
            long long h=ele.second;
            ans+=(h*(h-1))/2;
        }
        return ans;
    }
};