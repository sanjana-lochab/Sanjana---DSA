class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c){
        queue<pair<int,int>> q;
        q.push({r,c});

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            grid[r][c] = '0';
            if(r-1>=0 && grid[r-1][c]=='1'){
                q.push({r-1,c});
                grid[r-1][c] = '0';
            }
            if(r+1<grid.size() && grid[r+1][c]=='1'){
                q.push({r+1,c});
                grid[r+1][c] = '0';
            }
            if(c-1>=0 &&grid[r][c-1]=='1' ){
                q.push({r,c-1});
                grid[r][c-1] = '0';
            }
            if(c+1 <grid[0].size()&& grid[r][c+1]=='1'){
                q.push({r,c+1});
                grid[r][c+1] = '0';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};