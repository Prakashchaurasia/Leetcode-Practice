class Solution {
public:
    int minOperations(string s) {

        int n = s.size();

        string temp = s;
        sort(temp.begin(), temp.end());

        if(s == temp) return 0;

        char mini = 'z';
        char maxi = 'a';
        for(int i = 0; i < n; i++){
            mini = min(mini, s[i]);
            maxi = max(maxi, s[i]);
        }

        if(s[0] == mini || s[n-1] == maxi) return 1;
        else if(s[0] == maxi && s[n-1] == mini) {
            if(n == 2) return -1;
            else {
                string a=s.substr(0,n-1);
                sort(a.begin(),a.end());
                a+=s[n-1];
                string b=a.substr(1);
                sort(b.begin(),b.end());
                b=a[0]+b;
                if(b==temp) return 2;
                else{
                    string c=s.substr(1);
                    sort(c.begin(),c.end());
                    c=s[0]+c;
                    string d=c.substr(0,n-1);
                    sort(d.begin(),d.end());
                    d+=c[n-1];
                   if(d==temp) return 2;
                   else return 3;
                }
                
            }
        }
        else return 2;       
    }
};