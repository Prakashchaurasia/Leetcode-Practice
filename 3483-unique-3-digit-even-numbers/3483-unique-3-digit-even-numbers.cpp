class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(digits[i]==0) continue;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                for(int k=0;k<n;k++){
                   if(k==i || k==j) continue;
                   if(digits[k]%2==0) {
                      int h=100*digits[i] + 10*digits[j] + digits[k];
                      st.insert(h);
                   }
                }
            }
        }
        return (int)st.size();
    }
};