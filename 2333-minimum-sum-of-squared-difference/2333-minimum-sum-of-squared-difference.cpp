
class Solution {
public:
    #define ll long long
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        ll t= k1 + k2;
        vector<int> freq(100001,0);
        for(int i=0;i<n;i++){
            int h=abs(nums1[i]-nums2[i]);
            freq[h]++;
        }
        ll sum=0;
        for(int i=freq.size()-1;i>0;i--){
            if(t==0) break;
            if(freq[i]>0){
                if(t>=freq[i]){
                    t-=freq[i];
                    freq[i-1]+=freq[i];
                    freq[i]=0;
                }
                else{
                    freq[i]-=t;
                    freq[i-1]+=t;
                    t=0;
                }
            }
        }
        for(int i=0;i<freq.size();i++){
            sum += (1LL * i * i * freq[i]);
        }
        return sum;
    }
};