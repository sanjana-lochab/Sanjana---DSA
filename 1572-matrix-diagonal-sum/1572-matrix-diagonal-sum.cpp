class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0;i<mat.size();i++){
            sum +=mat[i][i];
        }
        int j = mat.size()-1;
        for(int i = 0;i<mat.size();i++){
            sum +=mat[i][j-i];   
        }
        if(n%2!=0){
            sum -=mat[n/2][n/2];
        }
        return sum;
    }
};