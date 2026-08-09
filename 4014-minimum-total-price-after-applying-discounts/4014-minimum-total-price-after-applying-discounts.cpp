class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double ans=0;
        int m=prices.size();
        int n=discounts.size();
        int i=0,j=0;
        sort(prices.begin(),prices.end(),greater<int> ());
        sort(discounts.begin(),discounts.end(),greater<int> ());
        while(i<m && j<n){
            ans+=(prices[i]*(100-discounts[j]))/100.0;
            i++;
            j++;
        }
        if(i<m){
            while(i<m){
                ans+=prices[i];
                i++;
            }
        }
        return ans;
    }
};