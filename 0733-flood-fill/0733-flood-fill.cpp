class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int value = image[sr][sc];
        if(value == color)
            return image;
            
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            image[r][c] = color;
            if(r-1>=0 && image[r-1][c]==value){
                q.push({r-1,c});
                image[r-1][c] = color;
            }
            if(r+1<image.size() && image[r+1][c]==value  ){
                q.push({r+1,c});
                image[r+1][c] = color;
            }
            if(c-1>=0 &&image[r][c-1]==value  ){
                q.push({r,c-1});
                image[r][c-1] = color;
            }
            if(c+1 <image[0].size()&& image[r][c+1]==value){
                q.push({r,c+1});
                image[r][c+1] = color;
            }
        }
        return image;
    }
};