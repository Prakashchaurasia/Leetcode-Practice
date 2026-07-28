class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<char> h;
        char mid='a';
        for(auto ele:mp){
          if(ele.second%2==0){
             for(int i=1;i<=ele.second/2;i++){
                h.push_back(ele.first);
             }
          }
          else {
            for(int i=1;i<=ele.second/2;i++){
                h.push_back(ele.first);
            }
            mid=ele.first;
          }
        }
        sort(h.begin(),h.end());
        string ans="";
        for(int i=0;i<h.size();i++){
            ans+=h[i];
        }
        string right = ans;
        reverse(right.begin(), right.end());
        if (n % 2 != 0) ans = ans + mid + right;
        else ans = ans + right;
        return ans;
    }
};