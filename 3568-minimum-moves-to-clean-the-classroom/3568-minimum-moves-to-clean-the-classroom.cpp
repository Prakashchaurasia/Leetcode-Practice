class Solution {
public:
    using VB    =vector<bool>;
    using VVB   =vector<VB>;
    using VVVB  =vector<VVB>;
    using VVVVB =vector<VVVB>;

    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};

    struct State{
        int row;
        int col;
        int energyLeft;
        int collectedmask;
    };
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size();
        int n=classroom[0].size();

        int maxEnergy=energy;
        int sr=0,sc=0;
        int litterBit[20][20];
        int litterCount=0;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                litterBit[r][c]=-1;
                if(classroom[r][c]=='S'){
                    sr=r;
                    sc=c;
                }
                else if(classroom[r][c]=='L'){
                    litterBit[r][c]=litterCount;
                    litterCount++;
                }
            }
        }

        int allCollected=(1<<litterCount)-1;
        if(litterCount==0) return 0;

        VVVVB vis(m,VVVB(n,VVB(maxEnergy+1,VB(1<<litterCount,false))));

        queue<State> qu;
        qu.push({sr,sc,maxEnergy,0});
        vis[sr][sc][maxEnergy][0]=true;

        int moves=0;
        while(!qu.empty()){
            int currSize=qu.size();
            while(currSize--){
               State curr=qu.front();
               qu.pop();
               if(curr.collectedmask==allCollected){
                return moves;
               }
               if(curr.energyLeft==0) continue;

               for(auto &dir:directions){
                 int nextRow=curr.row+dir[0];
                 int nextCol=curr.col+dir[1];
                 if(nextRow<0 || nextRow>=m || nextCol<0 || nextCol>=n) continue;
                 char cell=classroom[nextRow][nextCol];
                 if(cell=='X') continue;
                 int nextEnergy=curr.energyLeft-1;
                 int nextcollectedmask=curr.collectedmask;
                 if(cell=='R'){
                    nextEnergy=maxEnergy;
                 }
                 else if(cell=='L'){
                    nextcollectedmask |= (1<<litterBit[nextRow][nextCol]);
                 }

                 if(!vis[nextRow][nextCol][nextEnergy][nextcollectedmask]){
                    vis[nextRow][nextCol][nextEnergy][nextcollectedmask]=true;
                    qu.push({nextRow,nextCol,nextEnergy,nextcollectedmask});
                 }
               }
            }
            moves++;
        }
        return -1;
    
        
    }
};