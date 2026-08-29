class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans=0;
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp.clear();
            if(i>0 && s[i]==s[i-1]) continue;
            for(int j=i;j<n;j++){
               mp[s[j]]++;
               if(mp[s[j]]>=k){
                    int x=0;
                    for(auto ele:mp){
                        if(ele.second<k){
                           x=-1;
                           break;
                        }
                    }
                    if(x==0) ans=max(ans,j-i+1);
               }
            }
        }
        return ans;
    }
};