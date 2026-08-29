class Solution {
public:
    long long appealSum(string s) {
        long long ans=0;
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                ans+=1LL * (i+1)*(n-i);
            }
            else if(mp.find(s[i])!=mp.end()){
                ans+=1LL *(i- mp[s[i]])*(n-i);
            }
            mp[s[i]]=i;
        }
        return ans;
    }
};