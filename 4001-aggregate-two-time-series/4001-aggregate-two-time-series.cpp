class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n1=series1.size();
        int n2=series2.size();
        int a=0;
        int b=0;
        vector<vector<int>> h;
        while(a<n1 && b<n2){
            if(series1[a][0]<series2[b][0]){
               if(b<n2) h.push_back({series1[a][0],series1[a][1],series2[b][1]});
               else h.push_back({series1[a][0],series1[a][1],0});
                a++;
            }
            else if(series1[a][0]>series2[b][0]){
                if(a<n1) h.push_back({series2[b][0],series1[a][1],series2[b][1]});
                else h.push_back({series2[b][0],0,series2[b][1]});
                b++;
            }
            else if(series1[a][0]==series2[b][0]){
                h.push_back({series1[a][0],series1[a][1],series2[b][1]});
                a++;
                b++;
            }
        }
        if(a<n1){
            while(a<n1){
                h.push_back({series1[a][0],series1[a][1],0});
                a++;
            } 
        }
        if(b<n2){
            while(b<n2){
                h.push_back({series2[b][0],0,series2[b][1]});
                b++;
            } 
        }
        vector<vector<int>> ans;
        for(int i=0;i<h.size();i++){
            ans.push_back({h[i][0],h[i][1]+h[i][2]});
        }
        return ans;
    }
};