class Solution {
public:
    static bool cmp(string a, string b) {
        if (a.length() != b.length()) {
            return a.length() < b.length();
        }
        return a < b;
    }
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> ans;
        int count=0;
        int l=0;
        int r=0;
        string st="";
        string p="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count++;
                r=i;
            }
            st+=s[i];
            if(count==k) break;
        }
        if(count<k) return p;

        ans.push_back(st);
        while(r<s.size()){
            if(s[l]=='0'){
                string st1=st.substr(1);
                ans.push_back(st1);
                st=st1;
                l++;
            }
            else{
                l++;
                r++;
                string st1=st.substr(1);
                while(r<s.size() && s[r]!='1'){
                   st1+='0';
                   r++;
                }
                if(r<s.size()){
                    st1+='1';
                    ans.push_back(st1);
                    st=st1;
                }
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans[0];
    }
};