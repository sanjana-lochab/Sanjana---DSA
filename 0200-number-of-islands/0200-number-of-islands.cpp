class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c,int n,int m){
        if(r<0 || c<0 ||r>=n ||c>=m || grid[r][c]!='1') return;
        grid[r][c] = '0';
        dfs(grid,r-1,c,n,m);
        dfs(grid,r+1,c,n,m);
        dfs(grid,r,c-1,n,m);
        dfs(grid,r,c+1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return count;
    }
};