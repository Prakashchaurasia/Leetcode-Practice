class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
        vector<int> depth(n);
        function<void(int, int)> dfs = [&](int node, int d) {
            depth[node] = d;
            for (int child : children[node]) {
                dfs(child, d + 1);
            }
        };
        dfs(0, 1);
        int h = *max_element(depth.begin(), depth.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * (h - depth[i] + 1);
        }
        return ans;
    }
};