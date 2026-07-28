class Solution {
public:
    int m, n;
    vector<vector<int>> vis;

    bool dfsCycle(int x, int y, int px, int py, vector<vector<char>>& grid) {
        vis[x][y] = 1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            if (grid[nx][ny] != grid[x][y])
                continue;

            // Ignore the parent cell
            if (nx == px && ny == py)
                continue;

            // Visited neighbour other than parent => cycle
            if (vis[nx][ny])
                return true;

            if (dfsCycle(nx, ny, x, y, grid))
                return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vis.assign(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfsCycle(i, j, -1, -1, grid))
                        return true;
                }
            }
        }

        return false;
    }
};