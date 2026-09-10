class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<t.size();i++){
            if(i==t.size()-1){
                ans=t[t.size()-1];
                break;
            }
            if(s[i]!=t[i]){
                ans=t[i];
                break;
            }
            
        }
        return ans;
    }
};