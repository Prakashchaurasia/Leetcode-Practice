class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=')') st.push(s[i]);
            else{
                string h="";
                while(st.top()!='('){
                   h+=st.top();
                   st.pop();
                }
                st.pop();
                for(int j=0;j<h.size();j++){
                    st.push(h[j]);
                }
            }
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};