class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = 0;
        int col = 0;
        int distance = 1;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
             return -1;
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,1,0,-1,1,-1,0,1};
        queue<pair<pair<int,int>,int>> q;
        q.push({{row,col},distance});
        while(!q.empty()){
            auto [dir,dis] = q.front();
            q.pop();
            int r = dir.first;
            int c = dir.second;
            grid[r][c] = 1;
            if(r==n-1&&c==m-1) return dis;
            for(int i = 0;i<8;i++){
                int drs = r + dr[i];
                int dcs = c + dc[i];
                if(drs>=0&& drs<n && dcs>=0 && dcs<m&& grid[drs][dcs]==0){
                    grid[drs][dcs] = 1;
                    q.push({{drs,dcs},dis+1});
                }
            }
        }
        return -1;
    }
};