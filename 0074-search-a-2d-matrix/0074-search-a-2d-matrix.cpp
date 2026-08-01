class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool flag=false;
        int a=0;
        int b=m-1;
        if(m>1){
            if(matrix[a][0]<=target && matrix[a+1][0]>target){
                for(int i=0;i<n;i++){
                    if(matrix[a][i]==target) return true;
                }
                return false;
            }
            else if(matrix[b][0]<=target){
                for(int i=0;i<n;i++){
                    if(matrix[b][i]==target) return true;
                }
                return false;
            }
            else{
                while(a<=b){              
                    int mid=(a+b)/2;
                    if(matrix[mid][0]<=target && matrix[mid+1][0]> target){
                        for(int i=0;i<n;i++){
                          if(matrix[mid][i]==target) return true;
                        }
                        return false;
                    }
                    else if(matrix[mid][0]<target && matrix[mid+1][0]<=target) a=mid+1;
                    else b=mid-1;
                }
            }
        }
        else if(m==1){
            for(int i=0;i<n;i++){
                if(matrix[0][i]==target) return true;
            }
        }
        return false;
    }
};