class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        unordered_map<char,int> mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        if(mp.size()<=8) return mp.size();
        else{
            int x=mp.size();
            int i=1;
            while(x>0){
                if(x>8) ans+=i*8;
                else ans+=i*x;
                x=x-8;
                i++;
            }
        }
        return ans;
    }
};