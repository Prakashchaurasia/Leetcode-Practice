class Solution {
public:
    void solve(int i, string &digits, string &s, vector<string> &h, vector<string> &ans) {
        if (i == digits.size()) {
            ans.push_back(s);
            return;
        }
        int idx = digits[i] - '2';
        for (int j = 0; j < h[idx].size(); j++) {
            s.push_back(h[idx][j]);
            solve(i + 1, digits, s, h, ans);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> h = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string s;
        solve(0, digits, s, h, ans);
        return ans;
    }
};