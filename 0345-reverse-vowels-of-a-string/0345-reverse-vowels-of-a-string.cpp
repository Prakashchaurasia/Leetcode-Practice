class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        int i=0,j=n-1;
        // unordered_set<char> st = {'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};
        while(i<j){
            char l=tolower(s[i]);
            char r=tolower(s[j]);
            if((l=='a' || l=='e' || l=='i' || l=='o' || l=='u') && (r=='a' || r=='e' || r=='i' || r=='o' || r=='u')){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++;
                j--; 
            }
            else if((l=='a' || l=='e' || l=='i' || l=='o' || l=='u')) j--;
            else if((r=='a' || r=='e' || r=='i' || r=='o' || r=='u')) i++;
            else{
                i++;
                j--;
            }

            // if(st.count(s[i]) && st.count(s[j])){
            //     char temp=s[i];
            //     s[i]=s[j];
            //     s[j]=temp;
            //     i++;
            //     j--;
            // }
            // else if(!st.count(s[i]) && !st.count(s[j])){
            //     i++;
            //     j--;
            // }
            // else if(st.count(s[i])) j--;
            // else i++;
        }
        return s;
    }
};