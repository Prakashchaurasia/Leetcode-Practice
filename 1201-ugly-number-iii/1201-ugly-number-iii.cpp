class Solution {
public:
    #define ll long long

    ll lcm(ll a,ll b){
        return a/gcd(a,b)*b;
    }

    int nthUglyNumber(int n,int a,int b,int c) {
        ll ab=lcm(a,b);
        ll ac=lcm(a,c);
        ll bc=lcm(b,c);
        ll abc=lcm(ab,c);

        ll lo=1,hi=2000000000LL;

        while(lo<hi){
            ll mid=lo+(hi-lo)/2;
            ll count=mid/a+mid/b+mid/c-mid/ab-mid/ac-mid/bc+mid/abc;

            if(count>=n) hi=mid;
            else lo=mid+1;
        }

        return lo;
    }
};