class Solution {
    multiset<int> leftSet, rightSet;
    long long sumL = 0, sumR = 0;
    int need;

    void add(int val) {
        if (leftSet.empty() || val <= *leftSet.rbegin()) {
            leftSet.insert(val);
            sumL += val;
        } else {
            rightSet.insert(val);
            sumR += val;
        }
    }

    void remove(int val) {
        auto it = leftSet.find(val);

        if (it != leftSet.end()) {
            leftSet.erase(it);
            sumL -= val;
        } else {
            it = rightSet.find(val);
            rightSet.erase(it);
            sumR -= val;
        }
    }

    void balance() {
        while ((int)leftSet.size() > need) {
            int val = *leftSet.rbegin();

            leftSet.erase(prev(leftSet.end()));
            sumL -= val;

            rightSet.insert(val);
            sumR += val;
        }

        while ((int)leftSet.size() < need) {
            int val = *rightSet.begin();

            rightSet.erase(rightSet.begin());
            sumR -= val;

            leftSet.insert(val);
            sumL += val;
        }
    }

    long long getCost() {
        long long median = *leftSet.rbegin();

        return median * (long long)leftSet.size() - sumL
             + sumR - median * (long long)rightSet.size();
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        leftSet.clear();
        rightSet.clear();
        sumL = sumR = 0;

        need = (x + 1) / 2;

        // Step 1: Calculate every window's cost
        vector<long long> cost;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                balance();
                cost.push_back(getCost());
            }
        }

        // Step 2: DP
        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // Step 3: Suffix DP
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {

                // Skip current index
                dp[i][j] = dp[i + 1][j];

                // Take window starting at i
                if (i + x <= n) {
                    dp[i][j] = min(
                        dp[i][j],
                        cost[i] + dp[i + x][j - 1]
                    );
                }
            }
        }

        return dp[0][k];
    }
};