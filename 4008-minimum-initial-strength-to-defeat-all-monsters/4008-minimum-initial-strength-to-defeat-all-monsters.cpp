class Solution {
public:
    long long minInitialStrength(vector<int>& m, vector<vector<int>>& b) {
        int n = m.size();       
        vector<long long> d(n + 1, 0);
        for (auto& v : b) {
            d[v[0]] += v[2];
            d[v[1] + 1] -= v[2];
        }
        
        vector<long long> p(n, 0);
        long long c = 0;
        for (int i = 0; i < n; i++) {
            c += d[i];
            p[i] = c;
        }
        
        long long s = 0;
        for (int i = n - 1; i >= 0; i--) {
            long long x = (long long)m[i] - p[i];
            long long y = (s > 0) ? (s + m[i]) : 0LL;
            s = max({0LL, x, y});
        }
        
        return s;
    }
};