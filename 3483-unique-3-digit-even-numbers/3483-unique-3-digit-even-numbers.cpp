class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[digits[i]]++;
        }
        int ans=0;
        for(int i=100;i<999;i++){
            unordered_map<int,int> h;
            h=mp;
            int t=0;
            int p=i;
            if(i%2==0){
               while(p>0){
                  if(h.count(p%10)){
                      h[p%10]--;
                      if(h[p%10]==0) h.erase(p%10);
                  }
                  else {
                    t=1;
                    break;
                  }
                  p/=10;
               }
               if(t==0) ans++;
            }
        }
        return ans;
    }
};