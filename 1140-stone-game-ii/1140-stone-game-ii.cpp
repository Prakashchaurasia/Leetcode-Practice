class Solution {
public:
    int n;
    int t[2][101][101];
    int solve(int turn, int M, int i, vector<int>& piles) {
        if (i >= n)
            return 0;
        if (t[turn][i][M] != -1) {
            return t[turn][i][M];
        }
        int stone = 0;
        int result = (turn == 1) ? -1 : INT_MAX;
        for (int x = 1; x <= min(2 * M, n - i); x++) {
            stone += piles[i + x - 1];
            if (turn == 1) { /// alice turn
                result = max(result, stone + solve(0, max(M, x), i + x, piles));
            } else {
                result = min(result, solve(1, max(M, x), i + x, piles));
            }
        }
        return t[turn][i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        memset(t, -1, sizeof(t));
        n = piles.size();
        return solve(1, 1, 0, piles);
    }
};