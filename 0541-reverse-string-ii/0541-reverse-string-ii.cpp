class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size(); 
        int i=0;
        bool flag=true;
        string ans="";
        while(i<n){
            if(flag){
                string h=s.substr(i,min(k,n-i));
                reverse(h.begin(),h.end());
                ans+=h;
                i+=k;
                flag=false;
            }
            else{
                string h=s.substr(i,min(k,n-i));
                ans+=h;
                i+=k;
                flag=true;
            }
        }
        return ans;
    }
};