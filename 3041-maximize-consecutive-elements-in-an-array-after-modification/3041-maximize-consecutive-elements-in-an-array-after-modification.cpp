class Solution {
public:
    vector<vector<int>> dp;
    int findMethod(vector<int>& nums,int start,int target){
        int j=lower_bound(begin(nums)+start,end(nums),target) - begin(nums);
        int n=nums.size();
        if(j<n && nums[j]==target){
            return j;
        }
        return -1;
    }
    int solve(int i,int inc,vector<int>& nums){
        int cv=nums[i]+inc;
        int len=1;

        if(dp[i][inc]!=-1) return dp[i][inc];

        int j=findMethod(nums,i+1,cv+1);
        if(j!=-1){
            len=max(len,1+solve(j,0,nums));
        }

        j=findMethod(nums,i+1,cv);
        if(j!=-1){
            len=max(len,1+solve(j,1,nums));
        }

        return dp[i][inc]=len;
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        dp.assign(n+1,vector<int> (2,-1));
        int result=1;
        for(int i=0;i<n;i++){
            result = max({result,solve(i,0,nums),solve(i,1,nums)});
        }
        return result;
    }
};