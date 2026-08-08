class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> suff(n,0);
        int rightMatch=0;
        int i=n-1;
        int j=m-1;
        while(i>=0){
            if(j>=0 && word2[j]==word1[i]){
                rightMatch++;
                j--;
            }
            suff[i]=rightMatch;
            i--;
        }
        vector<int> seq;
        i=0;
        j=0;
        bool hasPower=true;
        while(i<n && j<m ){
            if(word1[i]==word2[j]){
                seq.push_back(i);
                j++;
            }
            else if(hasPower && i+1<n && suff[i+1]>=m-1-j){
                seq.push_back(i);
                j++;
                hasPower=false;
            }
            i++;
        }
        if(j==m) return seq;
        return {};
    }
};