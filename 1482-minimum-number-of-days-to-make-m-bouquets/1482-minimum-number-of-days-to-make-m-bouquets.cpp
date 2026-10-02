class Solution {
public:
    int minDays(vector<int>& bloomday, int m, int k) {
        int n=bloomday.size();
        int l=*min_element(bloomday.begin(),bloomday.end());
        int h=*max_element(bloomday.begin(),bloomday.end());
        // if(m*k>n) return -1;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int c=0;
            int a=0;
            for(int i=0;i<n;i++){
                if(bloomday[i]<=mid){
                    c++;
                    if(c==k){
                        a++;
                        c=0;
                    }
                }
                else c=0;
            }
            if(a>=m){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};