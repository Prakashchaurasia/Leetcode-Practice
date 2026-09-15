
class Solution {
  public:
    bool search(vector<int>& arr, int key) {
        // Code Here
        int n=arr.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(arr[m]==key) return true;
            if(arr[l]==arr[m] && arr[m]==arr[h]){
                l++;
                h--;
            }
            else if(arr[m]>=arr[l] ){
                if(arr[l]<=key && key<=arr[m]){
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }
            else{
                if(arr[m]<=key && key<=arr[h]){
                    l=m+1;
                }
                else h=m-1;
            }
        }
        return false;
    }
};