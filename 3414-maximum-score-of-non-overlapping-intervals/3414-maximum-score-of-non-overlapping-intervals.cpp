class Solution {
public:
    struct Node {
        long long score = -1;
        vector<int> idx;
    };
    vector<vector<Node>> dp;
    Node f(vector<vector<int>>& nums, int i, int k, vector<int>& nxt) {
        if (k == 0 or i >= nums.size()) return Node();
        if (dp[i][k].score != -1) return dp[i][k];
        Node skip = f(nums, i + 1, k, nxt); // not take
        int wt = nums[i][2];
        int idx = nums[i][3];
        int j = nxt[i];
        Node temp = f(nums, j, k - 1, nxt); // take
        Node take;
        take.score = wt + temp.score;
        take.idx = temp.idx;
        take.idx.push_back(idx);
        sort(take.idx.begin(), take.idx.end()); // sort the indexes
        Node res;
        if (take.score > skip.score) {
            res = take;
        } else if (skip.score > take.score) {
            res = skip;
        } else {
            res = (skip.idx < take.idx) ? skip : take;
        }
        return dp[i][k] = res;
    }
    int findNxt(vector<vector<int>>& nums, int end) { // binary search to find nxt idx
        int l = 0, r = nums.size() - 1;
        int ans = nums.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid][0] > end) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
    vector<int> maximumWeight(vector<vector<int>>& nums) {
        int n = nums.size();
        dp.assign(n + 1, vector<Node>(5));
        for (int i = 0; i < n; i++) {
            nums[i].push_back(i);
        }
        sort(nums.begin(), nums.end()); // sort the vector
        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            int end = nums[i][1];
            nxt[i] = findNxt(nums, end); // find next intervals
        }
        return f(nums, 0, 4, nxt).idx;
    }
};