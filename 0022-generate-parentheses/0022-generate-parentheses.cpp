class Solution {
public:
   void helper(string s,int open,int close,int n,vector<string>& v){
    if(open==n && close==n){
        v.push_back(s);
        return ;
    }
    if(open>=close){
       if(open<n)  helper(s+'(',open+1,close,n,v);
       if(close<n) helper(s+')',open,close+1,n,v);
    }
  }   
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        helper("",0,0,n,v);
        return v;
    }
};