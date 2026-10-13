class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> h(n);
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(abs(nums[i]));
        }
        int i=0;
        while(i<n){
           h[i]=pq.top();
           pq.pop();
           i+=2;
        }
        i=1;
        while(i<n){
           h[i]=pq.top();
           pq.pop();
           i+=2;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans+=(1LL*h[i]*h[i]);
            }
            else ans-=(1LL*h[i]*h[i]);
        }
        return ans;
    }
};