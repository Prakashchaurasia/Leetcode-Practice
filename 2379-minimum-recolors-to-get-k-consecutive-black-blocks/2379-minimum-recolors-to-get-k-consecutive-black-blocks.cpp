class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count=0;
        int n=blocks.size();
        int ans=INT_MAX;
        for(int i=0;i<k;i++){
           if(blocks[i]=='W') count++;
        }
        ans=min(ans,count);
        int l=0;
        int r=k;
        while(r<n){
            if(blocks[l]=='W' && blocks[r]=='B'){
                 count--;
                 ans=min(ans,count);
            }
            else if(blocks[l]=='B' && blocks[r]=='W'){
                count++;
                ans=min(ans,count);
            }
            l++;
            r++;
        }
        return ans;
    }
};