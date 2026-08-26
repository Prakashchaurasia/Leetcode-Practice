class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0,l=0,r=0,count=0;
        unordered_map<int,int> mp;
        int n=fruits.size();
        for(int i=0;i<n;i++){
            if(mp.count(fruits[i])==0 && (int)mp.size()<2){
                mp[fruits[i]]++;
                count++;
            }
            else if(mp.count(fruits[i])==0 && (int)mp.size()>=2){
                r=i;
                break;
            }
            else if(mp.count(fruits[i])!=0 && (int)mp.size()<=2){
                mp[fruits[i]]++;
                count++;
            }
        }
        ans=max(ans,count);
        while(r<n){
            mp[fruits[r]]++;
            while((int)mp.size()>2){
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
            r++;

        }
        ans=max(ans,r-l);
        return ans;
    }
};