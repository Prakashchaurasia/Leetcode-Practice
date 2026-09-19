class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x=min(x2,max(x1,xCenter));
        int y=min(y2,max(y1,yCenter));
        int d=(x-xCenter)*(x-xCenter)+(y-yCenter)*(y-yCenter);
        if(d<=radius*radius) return true;
        return false;
    }
};