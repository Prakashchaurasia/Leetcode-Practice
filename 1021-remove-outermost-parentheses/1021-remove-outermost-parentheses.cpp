class Solution {
public:
    string removeOuterParentheses(string s) {
       int count=0;
       int n=s.size();
       string ans="";
       for(int i=0;i<n;i++){
           if(s[i]=='('){
            if(count>0) ans+=s[i];
             count++;
           }
           if(s[i]==')'){

             count--;
             ans+=s[i];
             if(count == 0) ans.pop_back();
           }
       }
       return ans;
    }
};