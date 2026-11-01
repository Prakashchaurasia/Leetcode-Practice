class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        // priority_queue<int> pq;
        // unordered_map<int,int> mp;
        // for(int i=0;i<n;i++){
        //     pq.push(nums[i]);
        //     mp[nums[i]]++;
        // }
        // if(mp.size()==1) return 0;
        // int count=0;
        // while((int)mp.size()!=1){
        //     int x=pq.top();
        //     pq.pop();
        //     if(mp[x]==1){
        //         mp[x]--;
        //         mp.erase(x);
        //     }
        //     mp[x-1]++;
        //     pq.push(x-1);
        //     count++;
        // }
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>0;i--){
            count+=(nums[i]-nums[0]);
        }
        return count;
    }
};