class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // First and last occurrence
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Generate valid intervals
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];
            bool ok = true;

            for (int j = l; j <= r; j++) {
                int x = s[j] - 'a';

                if (first[x] < l) {
                    ok = false;
                    break;
                }

                r = max(r, last[x]);
            }

            if (ok)
                intervals.push_back({l, r});
        }

        // Interval scheduling
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) { return a.second < b.second; });

        vector<string> ans;
        int prevEnd = -1;

        for (auto [l, r] : intervals) {
            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};