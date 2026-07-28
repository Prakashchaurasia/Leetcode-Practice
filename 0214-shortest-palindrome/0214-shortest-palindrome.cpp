class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        // Create combined string
        string temp = s + "#" + rev;

        // Build LPS array
        vector<int> lps(temp.size(), 0);
        int len = 0;
        for (int i = 1; i < temp.size(); ) {
            if (temp[i] == temp[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        // Characters not in the longest palindromic prefix
        string add = s.substr(lps.back());
        reverse(add.begin(), add.end());
        return add + s;
    }
};