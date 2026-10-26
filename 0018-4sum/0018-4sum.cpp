class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        long long a=0,b=0,c=0,d=0;
        for(int i=0;i<n-3;i++){
            a=nums[i];
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                b=nums[j];
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                for(int k=j+1;k<n-1;k++){
                    c=nums[k];
                    if(k>j+1 && nums[k]==nums[k-1]) continue;
                    for(int l=k+1;l<n;l++){
                        if(l>k+1 && nums[l]==nums[l-1]) continue;
                        d=nums[l];
                        if(a+b+c+d==target){
                            vector<int> v;
                            v.push_back(a);
                            v.push_back(b);
                            v.push_back(c);
                            v.push_back(d);
                            st.insert(v);
                        }

                    }
                }
            }
        }
        for(auto ele:st){
            ans.push_back(ele);
        }
        return ans;
    }
};