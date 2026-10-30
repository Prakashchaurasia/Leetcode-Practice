class Solution {
public:
    typedef long long ll;
    ll inf = 1e18;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);

        for (auto& e : edges) {
            g[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<ll>> d(n, vector<ll>(k + 1, inf));

        priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> q;

        d[0][1] = 0;
        q.push({0, {0, 1}});
        while (!q.empty()) {
            auto t = q.top();
            q.pop();

            ll w = t.first;
            int u = t.second.first;
            int c = t.second.second;

            if (w != d[u][c])
                continue;

            for (auto& i : g[u]) {
                int v = i.first;
                int x = i.second;

                int y;
                if (labels[u] == labels[v])
                    y = c + 1;
                else
                    y = 1;

                if (y > k)
                    continue;
                ll z = w + x;

                if (z < d[v][y]) {
                    d[v][y] = z;
                    q.push({z, {v, y}});
                }
            }
        }
        ll ans = inf;
        for (int i = 1; i <= k; i++) {
            ans = min(ans, d[n - 1][i]);
        }
        return ans == inf ? -1 : ans;
    }
};