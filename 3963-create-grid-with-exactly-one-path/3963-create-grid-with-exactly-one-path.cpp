class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string a="";
        for(int i=0;i<n;i++){
            a+=".";
        }
        ans.push_back(a);
        for(int i=1;i<m;i++){
            string b="";
            for(int j=0;j<n;j++){
                if(j==n-1) b+=".";
                else b+="#";
            }
            ans.push_back(b);
        }
        return ans;
    }
};