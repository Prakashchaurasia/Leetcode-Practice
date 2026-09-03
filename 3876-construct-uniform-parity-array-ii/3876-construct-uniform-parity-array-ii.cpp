class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        if(n==1) return true;
        int a=0;
        int b=0;
        int x=INT_MAX;
        int y=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                x=min(x,nums1[i]);
                a++;
            }
            else {
                b++;
               y=min(y,nums1[i]);
            }
        }
        if(a==n || b==n) return true;
        a=0;
        b=0;
        vector<int> nums2(n);
        for(int i=0;i<n;i++){
          if(nums1[i]%2!=0) nums2[i]=nums1[i];
          else nums2[i]=nums1[i]-y;
        }
        for(int i=0;i<n;i++){
            if(nums2[i]>=1 && nums2[i]%2!=0) b++;
        }
        if(a==n || b==n) return true;
        return false;
    }
};