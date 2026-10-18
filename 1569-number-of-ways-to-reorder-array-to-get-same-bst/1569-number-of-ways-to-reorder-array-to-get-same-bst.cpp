class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    long long nCr(int n, int r) {
        return fact[n] * invFact[r] % MOD
             * invFact[n - r] % MOD;
    }

    long long solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long ans = nCr(n - 1, left.size());
        ans = ans * solve(left) % MOD;
        ans = ans * solve(right) % MOD;

        return ans;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        fact.resize(n + 1);
        invFact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[n] = power(fact[n], MOD - 2);

        for (int i = n - 1; i >= 0; i--)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;

        return (solve(nums) - 1 + MOD) % MOD;
    }
};