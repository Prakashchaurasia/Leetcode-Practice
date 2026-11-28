
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n+1, 0);
        int minPrice = INT_MAX;
        for(auto &x : items) {
            freq[x[0]]++;
            minPrice = min(minPrice, x[1]);
        }
        vector<int> gain(n+1, 0);
    
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j += i) {
                gain[i] += freq[j];
            }
        }

        vector<pair<int,int>> v;

        for(auto &x : items) {
            int f = x[0];
            int p = x[1];

            int cnt = gain[f] - 1;

            if(cnt > 0 && p < 2 * minPrice) {
                v.push_back({p, cnt});
            }
        }
        sort(v.begin(), v.end());
        long long ans = 0;
        long long rem = budget;
        for(auto &x : v) {
            long long price = x.first;
            long long cnt = x.second;

            long long take = min(cnt, rem / price);

            ans += 2 * take;
            rem -= take * price;
        }
        ans += rem / minPrice;

        return (int)ans;
    }
};
