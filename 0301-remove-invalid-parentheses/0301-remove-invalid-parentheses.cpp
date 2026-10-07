class Solution {
public:
    unordered_set<string> ans;
    void solve(string &s, int i, int leftRemove, int rightRemove,  int balance, string temp) {
        if (i == s.size()) {
            if (leftRemove == 0 && rightRemove == 0 && balance == 0) {
                ans.insert(temp);
            }
            return;
        }
        char ch = s[i];
        if (ch == '(' && leftRemove > 0) {
            solve(s, i + 1, leftRemove - 1, rightRemove,
                  balance, temp);
        }
        if (ch == ')' && rightRemove > 0) {
            solve(s, i + 1, leftRemove, rightRemove - 1,
                  balance, temp);
        }
        if (ch != '(' && ch != ')') {
            solve(s, i + 1, leftRemove, rightRemove,
                  balance, temp + ch);
        }
        else if (ch == '(') {
            solve(s, i + 1, leftRemove, rightRemove,  balance + 1, temp + ch);
        }
        else {
            if (balance > 0) {
                solve(s, i + 1, leftRemove, rightRemove,  balance - 1, temp + ch);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {\
        int leftRemove = 0;
        int rightRemove = 0;
        for (char ch : s) {
            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {
                if (leftRemove > 0) leftRemove--;
                else  rightRemove++;
            }
        }
        solve(s, 0, leftRemove, rightRemove, 0, "");
        return vector<string>(ans.begin(), ans.end());
    }
};