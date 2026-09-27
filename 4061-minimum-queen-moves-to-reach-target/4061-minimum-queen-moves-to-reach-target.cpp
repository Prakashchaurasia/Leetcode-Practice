class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int a=source[0];
        int b=source[1];
        int c=target[0];
        int d=target[1];
        if(a==c && b==d) return 0;
        else if(a==c || b==d) return 1;
        else if(a+b==c+d) return 1;
        else if(a+d==c+b) return 1;
        else return 2;
    }
};