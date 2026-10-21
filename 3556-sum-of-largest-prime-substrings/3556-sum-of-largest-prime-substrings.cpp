class Solution {
public:
    bool isPrime(long long x){
        if(x<2) return false;
        if(x==2) return true;
        if(x%2==0) return false;
        for(long long i=3;i*i<=x;i+=2){
            if(x%i==0) return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        unordered_set<long long> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum=10*sum+(s[j]-'0');
                if(isPrime(sum)){
                    st.insert(sum);
                }
            }
        }
        vector<long long> h;
        for(auto ele:st){
            h.push_back(ele);
        }
        sort(h.begin(),h.end());
        long long ans=0;
        if(h.size()==0) return 0;
        else if(h.size()==1) return h[0];
        else if(h.size()==2) return h[0]+h[1]; 
        else if(h.size()==3) return h[0]+h[1]+h[2];
        else{
           for(int i=h.size()-1;i>h.size()-4;i--){
              ans+=h[i];
           }
           return ans;
        }
        return 0;
    }
};