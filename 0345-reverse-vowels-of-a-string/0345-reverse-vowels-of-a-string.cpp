class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        int i=0,j=n-1;
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};
        while(i<j){
            if(st.count(s[i]) && st.count(s[j])){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--;
            }
            else if(st.count(s[i])) j--;
            else if(st.count(s[j])) i++;
            else{
                i++;
                j--;
            }
        }
        return s;
    }
};