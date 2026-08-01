class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n,vector<int> (n));
        int minr=0;
        int minc=0;
        int maxr=n-1;
        int maxc=n-1;
        int count=1;
        while(minr<=maxr && minc<=maxc){
            //right
            for(int j=minc;j<=maxc;j++){
                arr[minr][j]=count++;
            }
            minr++;
            if(minr>maxr || minc>maxc) break;
            //down
            for(int j=minr;j<=maxr;j++){
                arr[j][maxc]=count++;
            }
            maxc--;
            if(minr>maxr || minc>maxc) break;
            //left
            for(int j=maxc;j>=minc;j--){
                arr[maxr][j]=count++;
            }
            maxr--;
            if(minr>maxr || minc>maxc) break;
            //up
            for(int j=maxr;j>=minr;j--){
                arr[j][minc]=count++;
            }
            minc++;
             if(minr>maxr || minc>maxc) break;
        }
        return arr;
    }
};