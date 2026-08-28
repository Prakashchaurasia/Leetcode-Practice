class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int r=0,l=0,maxLength=0,maxFreq=0;
        unordered_map<char,int> mp;
        vector<int> count(26, 0);
        while(r<s.size()){
            count[s[r]-'A']++;
            maxFreq=max(maxFreq,count[s[r]-'A']);
            if((r-l+1)-maxFreq>k){
                count[s[l]-'A']--;
                l+=1;
            }
            else if((r-l+1)-maxFreq<=k){
                maxLength=max(maxLength,r-l+1);
            }
            r++;
        }
        return maxLength;
    }
};