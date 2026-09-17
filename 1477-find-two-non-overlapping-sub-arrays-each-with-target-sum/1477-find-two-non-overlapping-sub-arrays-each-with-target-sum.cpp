class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;
        int best = INT_MAX, res = INT_MAX, currSum = 0;
        vector<int> bestIdx(n);
        while (j < n) {
            currSum += arr[j];
            while (i < j and currSum > target) {
                currSum -= arr[i++];
            }
            if (currSum == target) {
                int len = j - i + 1;
                if (i > 0 and bestIdx[i - 1] != INT_MAX) {
                    res = min(res, len + bestIdx[i - 1]);
                }
                best = min(best, len);
            }
            bestIdx[j] = best;
            j++;
        }
        return res == INT_MAX ? -1 : res;
    }
};