class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        unordered_set<int> st;
        int mdays[]={31,28,31,30,31,30,31,31,30,31,30,31};

        int aMonArrive=stoi(string() +arriveAlice[0]+arriveAlice[1]);
        int aDayArrive=stoi(string() +arriveAlice[3]+arriveAlice[4]);

        int bMonArrive=stoi(string() +arriveBob[0]+arriveBob[1]);
        int bDayArrive=stoi(string() +arriveBob[3]+arriveBob[4]);

        int aMonLeave=stoi(string() +leaveAlice[0]+leaveAlice[1]);
        int aDayLeave=stoi(string() +leaveAlice[3]+leaveAlice[4]);

        int bMonLeave=stoi(string() +leaveBob[0]+leaveBob[1]);
        int bDayLeave=stoi(string() +leaveBob[3]+leaveBob[4]);

        int d1=0;
        for(int i=0;i<aMonArrive-1;i++){
            d1+=mdays[i];
        }
        d1+=aDayArrive;

        int d2=0;
        for(int i=0;i<aMonLeave-1;i++){
            d2+=mdays[i];
        }
        d2+=aDayLeave;

        int d3=0;
        for(int i=0;i<bMonArrive-1;i++){
            d3+=mdays[i];
        }
        d3+=bDayArrive;

        int d4=0;
        for(int i=0;i<bMonLeave-1;i++){
            d4+=mdays[i];
        }
        d4+=bDayLeave;

        for(int i=d1;i<=d2;i++){
            st.insert(i);
        }
        int c=0;
        for(int i=d3;i<=d4;i++){
            if(st.count(i)) c++;
        }
        return c;

        
    }
};