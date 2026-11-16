class Solution {
public:
    string digitSum(string s, int k) {
        string ans=s;
        while(ans.size()>k){
            int n=ans.size();
            string h="";
            for(int i=0;i<n;i+=k){
                int s=0;
                for(int j=i;j<min(n,i+k);j++){
                    s+=ans[j]-'0';
                }
                h+=to_string(s);
            }
            ans=h;

        }
        return ans;
    }
};