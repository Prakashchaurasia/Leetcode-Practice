class Solution {
public:
    bool possible(vector<vector<int>>& mat, vector<vector<int>>& pref, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;
        for (int i = 0; i + k <= m; i++) {
            for (int j = 0; j + k <= n; j++) {
                int sum = pref[i + k][j + k] - pref[i][j + k] - pref[i + k][j]+ pref[i][j];
                if (sum != k * k) continue;
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
        if (maxRow == -1) return false;
        if (maxRow - minRow >= k) return true;
        if (maxCol - minCol >= k) return true;
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[i + 1][j + 1] = mat[i][j] + pref[i][j + 1] + pref[i + 1][j] - pref[i][j];
            }
        }
        int low = 1;
        int high = min(m, n);
        int ans = 0;
        while (low <= high) {
            int k = low + (high - low) / 2;
            if (possible(mat, pref, k)) {
                ans = k;
                low = k + 1;
            } else {
                high = k - 1;
            }
        }
        return ans * ans;
    }
};