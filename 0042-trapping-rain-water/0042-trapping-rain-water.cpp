class Solution {
public:
    int trap(vector<int>& height) {
       int n=height.size();
       vector<int> prev(n);
       prev[0]=-1;
       int max=height[0];
       for(int i=1;i<n;i++){
        prev[i]=max;
        if(max<height[i]) max=height[i];
       }
      vector<int> next(n);
       next[n-1]=-1;
       max=height[n-1];
       for(int i=n-2;i>=0;i--){
        next[i]=max;
        if(max<height[i]) max=height[i];
       }
       vector<int> mini(n);
       mini[0]=-1;
       mini[n-1]=-1;
       for(int i=1;i<n-1;i++){
        mini[i]=min(prev[i],next[i]);
       }
       int waterunit=0;
       for(int i=0;i<n;i++){
          if(height[i]<mini[i]){
           waterunit+=(mini[i]-height[i]);
          }
       }
       return waterunit;
    }  
};