class Solution {
public:
    bool canAliceWin(int n) {
        int x=10;
        int c=0;
        while(n>=x){
            c++;
            n-=x;
            x--;
        }
        if(c%2==1) return true;
        return false;
    }
};