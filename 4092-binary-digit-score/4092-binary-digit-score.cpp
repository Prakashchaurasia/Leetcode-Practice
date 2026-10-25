class Solution {
public:
    int calculateScore(int a, int b) {
        int s1=0,s2=0;
        int x=a,y=b;
        while(x>0){
            s1+=(x&1);
            x=x>>1;
        }
        while(y>0){
            s2+=(y&1);
            y=y>>1;
        }
        if(s1>=s2) return s1*s2;
        return s2/s1;
    }
};