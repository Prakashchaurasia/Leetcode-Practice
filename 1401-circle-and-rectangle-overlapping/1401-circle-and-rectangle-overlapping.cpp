class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        if (xCenter >= x1 && xCenter <= x2 && yCenter >= y1 && yCenter <= y2) return true;

        double d= radius*radius - (x1 - xCenter)*(x1 - xCenter);
        if(d>=0){
            double yA=yCenter+sqrt(d);
            double yB=yCenter-sqrt(d);
            if((yA>=y1 && yA<=y2) || (yB>=y1 && yB<=y2)) return true;
        }

        d= radius*radius - (x2 - xCenter)*(x2 - xCenter);
        if(d>=0){
            double yA=yCenter+sqrt(d);
            double yB=yCenter-sqrt(d);
            if((yA>=y1 && yA<=y2) || (yB>=y1 && yB<=y2)) return true;
        }
        
        d= radius*radius - (y1 - yCenter)*(y1 - yCenter);
        if(d>=0){
            double xA=xCenter+sqrt(d);
            double xB=xCenter-sqrt(d);
            if((xA>=x1 && xA<=x2) || (xB>=x1 && xB<=x2)) return true;
        }

        d= radius*radius - (y2 - yCenter)*(y2 - yCenter);
        if(d>=0){
            double xA=xCenter+sqrt(d);
            double xB=xCenter-sqrt(d);
            if((xA>=x1 && xA<=x2) || (xB>=x1 && xB<=x2)) return true;
        }

        double d1 = (x1-xCenter)*(x1-xCenter) + (y1-yCenter)*(y1-yCenter);
        double d2 = (x1-xCenter)*(x1-xCenter) + (y2-yCenter)*(y2-yCenter);
        double d3 = (x2-xCenter)*(x2-xCenter) + (y1-yCenter)*(y1-yCenter);
        double d4 = (x2-xCenter)*(x2-xCenter) + (y2-yCenter)*(y2-yCenter);

        if (d1 <= radius*radius || d2 <= radius*radius || d3 <= radius*radius || d4 <= radius*radius) return true;

        return false;

    }
};