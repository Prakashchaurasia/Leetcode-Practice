class Solution {
public:
    int LOG, n, timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, depth, bit;
    string s;

    void update(int i, int val) {
        for (i++; i <= n; i += i & -i) bit[i] ^= val;
    }

    void rangeUpdate(int l, int r, int val) {
        update(l, val);
        if (r + 1 < n) update(r + 1, val);
    }

    int query(int i) {
        int ans = 0;
        for (i++; i > 0; i -= i & -i) ans ^= bit[i];
        return ans;
    }

    void dfs(int root) {
        stack<tuple<int, int, int>> st;
        st.push({root, root, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.top();
            st.pop();

            if (state == 0) {
                tin[u] = timer++;
                up[0][u] = p;

                for (int k = 1; k < LOG; k++) up[k][u] = up[k - 1][up[k - 1][u]];

                st.push({u, p, 1});

                for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                    int v = adj[u][i];
                    if (v == p) continue;

                    depth[v] = depth[u] + 1;
                    st.push({v, u, 0});
                }
            } else {
                tout[u] = timer - 1;
            }
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int d = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++)
            if (d & (1 << k)) u = up[k][u];

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,  string s, vector<string>& queries) {
        this->n = n;
        this->s = s;
        timer = 0;

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        adj.assign(n, {});
        up.assign(LOG, vector<int>(n));
        tin.resize(n);
        tout.resize(n);
        depth.assign(n, 0);
        bit.assign(n + 1, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0);
        for (int i = 0; i < n; i++) rangeUpdate(tin[i], tout[i], 1 << (s[i] - 'a'));
        vector<bool> ans;

        for (string q : queries) {
            stringstream ss(q);
            string type;
            int u, v;
            ss >> type >> u;
            if (type == "update") {
                char c;
                ss >> c;
                int change = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                rangeUpdate(tin[u], tout[u], change);
                s[u] = c;
            } else {
                ss >> v;
                int w = lca(u, v);
                int mask = query(tin[u]) ^ query(tin[v]) ^ (1 << (s[w] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};