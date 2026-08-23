class Solution {
public:
    bool isPalindromic(string s) {
        int n=s.size();
        string p="";
        for(int i=0;i<n;i++){
            int x=s[i];
            string h="";
            while(x>0){
                h+=to_string(x%2);
                x/=2;
            }
            reverse(h.begin(),h.end());
            if(h.size()!=8){
                for(int j=8;j>h.size();j--){
                    h='0'+h;
                }
            }
            p+=h;
        }
        int i=0,j=(int)p.size()-1;
        while(i<j){
            if(p[i]!=p[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};