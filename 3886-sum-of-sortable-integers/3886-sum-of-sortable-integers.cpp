class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> divisor;
        vector<int> prefMax(n + 1, INT_MIN);
        vector<int> suffMin(n + 1, INT_MAX);
        vector<int> drop(n, 0);

        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        for (int i = 1; i < n; i++) {
            drop[i] = drop[i - 1] + (nums[i - 1] > nums[i]);
        }

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisor.push_back(i);

                if (i != n / i)
                    divisor.push_back(n / i);
            }
        }

        int ans = 0;

        for (int k : divisor) {
            bool ok = true;

            for (int i = 0; i < n; i += k) {
                int j = i + k - 1;
                int cnt = drop[j] - drop[i];

                if (nums[j] > nums[i])
                    cnt++;

                if (cnt > 1 || prefMax[i] > suffMin[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans += k;
        }

        return ans;
    }
};