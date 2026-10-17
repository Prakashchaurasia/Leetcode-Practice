
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++) {
            int s = 0, x = nums[i];

            while (x > 0) {
                s += x % 10;
                x /= 10;
            }

            v[i] = {s, nums[i]};
        }

        vector<pair<pair<int, int>, int>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {v[i], i};
        }

        sort(a.begin(), a.end());

        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || a[i].second == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = true;
                j = a[j].second;
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};
