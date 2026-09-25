class Solution {
public:
    set<string> merge(set<string>& a, set<string>& b) {
        set<string> ans;
        for(auto x : a) {
            for(auto y : b) {
                ans.insert(x + y);
            }
        }
        return ans;
    }
    set<string> f(string& s, int& i) {
        set<string> ans;
        set<string> cur;
        while(i < s.size() && s[i] != '}') {
            if(s[i] == ',') {
                // Union
                for(auto x : cur)
                    ans.insert(x);
                cur.clear();
                i++;
            }
            else if(s[i] == '{') {
                i++;  // skip '{'
                set<string> temp = f(s, i);
                i++;  // skip '}'
                if(cur.empty()) {
                    cur = temp;
                }
                else {
                    cur = merge(cur, temp);
                }
            }
            else {
                // Single character
                set<string> temp;
                temp.insert(string(1, s[i]));
                if(cur.empty()) {
                    cur = temp;
                }
                else {
                    cur = merge(cur, temp);
                }
                i++;
            }
        }
        // Add last expression
        for(auto x : cur)
            ans.insert(x);
        return ans;
    }
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> st = f(expression, i);
        return vector<string>(st.begin(), st.end());
    }
};