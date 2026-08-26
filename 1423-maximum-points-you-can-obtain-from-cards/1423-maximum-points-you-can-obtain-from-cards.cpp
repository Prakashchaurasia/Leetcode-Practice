class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> preSum(n);
        vector<int> suffSum(n);
        preSum[0]=cardPoints[0];
        suffSum[n-1]=cardPoints[n-1];
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+cardPoints[i];
            suffSum[n-1-i]=suffSum[n-i]+cardPoints[n-1-i];
        }
        int ans=INT_MIN;
        for(int i=0;i<=k;i++){
            if(i==0){
                ans=max(ans,suffSum[n-k]);
            }
            else if(i==k){
                ans=max(ans,preSum[k-1]);
            }
            else{
                ans=max(ans,preSum[i-1]+suffSum[n-k+i]);
            }
        }
        return ans;
    }
};