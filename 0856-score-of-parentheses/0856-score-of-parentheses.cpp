class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        stack<int> st;
        for(char ch : s) {
            if(ch == '(') {
                st.push(ans);
                ans = 0;
            }
            else {
                if(ans == 0) ans = 1;
                else ans *= 2;
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
};