class Solution {
public:
    string result = "";
    vector<int> count = vector<int>(26, 0);
    bool solve(string& curr, vector<int>& count, string& target, int i,bool greater) {

        int n = target.size();

        // We only construct first half
        if (i == n / 2) {

            string right = curr;
            reverse(right.begin(), right.end());

            string temp = curr;

            // middle character for odd length
            if (n % 2 == 1) {
                for (int j = 0; j < 26; j++) {
                    if (count[j] == 1) {
                        temp += char('a' + j);
                        break;
                    }
                }
            }

            temp += right;

            if (temp > target) {
                result = temp;
                return true;
            }

            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {

            // Need TWO copies
            if (count[ch - 'a'] < 2) continue;
            if (!greater && ch < target[i]) continue;
            curr.push_back(ch);

            // Use two copies
            count[ch - 'a'] -= 2;

            bool isGreater = greater || ch > target[i];

            if (solve(curr, count, target, i + 1, isGreater))
                return true;

            curr.pop_back();
            count[ch - 'a'] += 2;
        }

        return false;
    }
    string lexPalindromicPermutation(string s, string target) {

        result = "";
        count.assign(26, 0);

        for (char ch : s) {
            count[ch - 'a']++;
        }

        // Check if palindrome is possible
        int odd = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] % 2)
                odd++;
        }

        if (odd > 1)
            return "";

        string curr;

        solve(curr, count, target, 0, false);

        return result;
    }
};