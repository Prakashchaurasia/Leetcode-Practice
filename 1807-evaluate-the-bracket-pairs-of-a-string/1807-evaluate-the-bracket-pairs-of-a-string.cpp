class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        int i=0;
        string ans="";
        while(i<s.size()){
            if(s[i]=='('){
                string h="";
                i++;
                while(s[i]!=')'){
                   h+=s[i];
                   i++;
                }
                if(mp.find(h)!=mp.end()) ans+=mp[h];
                else ans+="?";
                i++ ;
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};