class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n=digits.size();
        int x=digits[n-1];
        int count=0;
        for(int i=0;i<n;i++){
              if(digits[n-1-i]==9) count++;
              else break;
        }
        if(count==n){
           ans.push_back(1);
           for(int i=0;i<count;i++){
            ans.push_back(0);
           }
            
        }
        else if(count<n && count>0){
            for(int i=0;i<n-count-1;i++){
                ans.push_back(digits[i]);
            }
            int y=digits[n-count-1];
            y=y+1;
            ans.push_back(y);
            for(int i=0;i<count;i++){
                ans.push_back(0);
            }    
        }
        else{
            x=x+1;
            for(int i=0;i<n;i++){
                ans.push_back(digits[i]);
            }
            ans.pop_back();
            ans.push_back(x);
        }
        return ans;
    }
};