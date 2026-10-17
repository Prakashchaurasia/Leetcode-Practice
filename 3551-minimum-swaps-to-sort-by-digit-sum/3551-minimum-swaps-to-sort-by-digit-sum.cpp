
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // {digit sum, value, original index}
        vector<tuple<int, int, int>> v;

        for (int i = 0; i < n; i++) {
            int x = nums[i], s = 0;

            while (x > 0) {
                s += x % 10;
                x /= 10;
            }

            v.push_back({s, nums[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            int originalIndex = get<2>(v[i]);
            pos[originalIndex] = i;
        }

        int swaps = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (vis[i] || pos[i] == i)
                continue;

            int j = i, cycle = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = pos[j];
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};
