class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int n=source.size();
        long long sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1+=source[i];
            sum2+=target[i];
        }
        if(sum1==sum2) return true;
        return false;
    }
};