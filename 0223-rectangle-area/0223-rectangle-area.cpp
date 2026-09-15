class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        bool flag= ax1<bx2 && ay1<by2 && bx1<ax2 && by1<ay2;
        if(flag){
            int x1=ax2-ax1;
            int y1=ay2-ay1;
            int x2=bx2-bx1;
            int y2=by2-by1;

            int a=max(ax1,bx1);
            int b=min(ax2,bx2);
            int c=max(ay1,by1);
            int d=min(ay2,by2);

            
            return ((x1*y1)+(x2*y2))-(abs(a-b)*abs(c-d));
        }
        else{
            int x1=ax2-ax1;
            int y1=ay2-ay1;
            int x2=bx2-bx1;
            int y2=by2-by1;
            return (x1*y1)+(x2*y2);
        }
        return 0;
    }
};