class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int p=0,q=0,r=0,s=0;
        unordered_map<char,int> mp;
        for(int i=0;i<word.size();i++){
            mp[word[i]]++;
        }
        if(mp.size()<=8) return n;
        else{
            vector<int> h;
            for(auto ele:mp){
                h.push_back(ele.second);
            }
            sort(h.begin(),h.end(), greater<int>());
            for(int i=0;i<h.size();i++){
                if(i<8) p+=h[i];
                else if(i<16) q+=(2*(h[i]));
                else if(i<24) r+=(3*(h[i]));
                else  s+=(4*(h[i]));
            }
        }
        return p+q+r+s;
    }
};