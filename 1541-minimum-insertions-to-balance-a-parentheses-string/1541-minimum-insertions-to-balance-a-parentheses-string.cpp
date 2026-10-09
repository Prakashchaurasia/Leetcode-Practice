class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int n=s.size();
        stack<char> st;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                 st.push('(');
                 i++;
            }
            else if(s[i]==')' && st.size()!=0){
                if(i+1<n && s[i+1]==')'){
                    i+=2;
                }
                else{
                    i++;
                    ans++;
                }
                st.pop();
            }
            else{
                if(i+1<n && s[i+1]==')'){
                    i+=2;
                    ans++;
                }
                else{
                    i++;
                    ans+=2;
                }
            }
        }
        ans+=2*st.size();
        return ans;
    }
};