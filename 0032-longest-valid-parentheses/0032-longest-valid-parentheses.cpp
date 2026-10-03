class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]==')') continue;
            int count=0;
            int o=0,c=0;
            for(int j=i;j<n;j++){
                if(s[j]=='(') o++;
                else{
                    c++;
                    if(c>o){
                        ans=max(ans,count);
                        break;
                    }
                    if(c==o){
                        count=c;
                        ans=max(ans,count);
                    }
                }
            }
        }
        return 2*ans;
    }
};