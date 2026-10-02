class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int ans=arr[0]-1;
        for(int i=n-1;i>=0;i--){
            if(arr[i]-(i+1)<k){
                ans=arr[i]+(k-(arr[i]-(i+1)));
                break;
            }
            if(arr[i]-(i+1)>=k && i==0) return arr[0]-(arr[0]-k);
        }
        return ans;
    }
};