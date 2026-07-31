class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();
        vector<int> rem(n);
        for(int i=0;i<n;i++){
            rem[i]=capacity[i]-rocks[i];
        }
        sort(rem.begin(),rem.end());
        int x=additionalRocks;
        int ans=0;
        for(int i=0;i<n;i++){
            if(x>=rem[i]) {
                ans++;
                x-=rem[i];
            }
            else break;
        }
        return ans;
    }
};