class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        if(n==1) return true;
        int a=0;
        int b=0;
        int x;
        int y;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                x=nums1[i];
                a++;
            }
            else {
                b++;
                y=nums1[i];
            }
        }
        if(a==n || b==n) return true;
        a=0;
        b=0;
        vector<int> nums2(n);
        for(int i=0;i<n;i++){
          if(nums1[i]%2==0) nums2[i]=nums1[i]-y;
          else nums2[i]=nums1[i]-x;
        }
        for(int i=0;i<n;i++){
            if(nums2[i]%2==0) a++;
            else b++;
        }
        if(a==n || b==n) return true;
        return false;
    }
};