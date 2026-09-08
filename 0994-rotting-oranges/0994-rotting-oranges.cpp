class Solution {
public:
    void bfs(vector<vector<int>>& grid,int n,int m,vector<pair<pair<int,int>,int>>& q,int& count,int& time){
        int front = 0;

        int dr[] ={-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(front < q.size()){

            int r = q[front].first.first;
            int c = q[front].first.second;
            int t = q[front].second;

            front++;

            time = max(time,t);

            for(int i = 0;i<4;i++){
                int nr = r+ dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nr<n &&nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc] = 2;

                    count--;
                    q.push_back({{nr,nc},t+1});
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<pair<int,int>,int>> q;
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2){
                    q.push_back({{i,j},0});
                }
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        int time = 0;

        // start BFS only once
        bfs(grid,n,m,q,count,time);

        //Fresh oranges still remaining
        if(count!=0) return -1;

        return time;
    }
};