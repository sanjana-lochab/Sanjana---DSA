class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        int sr = entrance[0];
        int sc = entrance[1];

        queue<pair<pair<int,int>,int>> q;
        q.push({{sr,sc},0});
        maze[sr][sc] = '+';
        
        int dr[] ={1,-1,0,0};
        int dc[] ={0,0,1,-1};
        while(!q.empty()){
            auto [dir,step] = q.front();
            q.pop();
            int r = dir.first;
            int c = dir.second;
            for(int k = 0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nc>=0 && nr<rows && nc<cols && maze[nr][nc]=='.'){

                    if(nr==0 ||nc==0 || nr==rows-1 ||nc==cols-1){
                        return step+1;
                    }
                    maze[nr][nc]='+';
                    q.push({{nr,nc},step+1});
                }
            }
            
        }
        return -1;
    }
};