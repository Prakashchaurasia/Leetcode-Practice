class Solution {
public:
    bool checkValidString(string s) {
        bool flag=true;
        int c=0,o=0,h=0;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') o++;
            else if(s[i]=='*') h++;
            else{
                c++;
                if(c>o+h){
                    return false;                    
                }
            }
        }
        c=0,o=0,h=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                o++;
                if(o>c+h){
                    return false;                    
                }
            }
            else if(s[i]=='*') h++;
            else{
                c++;
            }
        }
        return true;
        
    }
};