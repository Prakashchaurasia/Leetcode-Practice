class Solution {
public:
    int romanToInt(string s) {
        int n=s.length();
        vector<int> v(n);
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
              v[i]=1;
            }
            else if(s[i]=='V'){
              v[i]=5;
            }
            else if(s[i]=='X'){
              v[i]=10;
            }
            else if(s[i]=='L'){
              v[i]=50;
            }
            else if(s[i]=='C'){
              v[i]=100;
            }
            else if(s[i]=='D'){
              v[i]=500;
            }
            else if(s[i]=='M'){
              v[i]=1000;
            }
        }
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(i==n-1) ans+=v[i];
            else{
                if(v[i+1]>v[i]) ans-=v[i];
                else ans+=v[i];
            }
        }
        return ans;
    }
};