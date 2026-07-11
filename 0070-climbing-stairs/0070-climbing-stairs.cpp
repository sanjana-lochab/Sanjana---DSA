class Solution {
public:
   // it is giving TLE
    int solveusingTDApproch(int n, vector<int> & dp){
        if(n==0) return 1;
        if(n==1) return 1;
        int ans = climbStairs(n-1)+climbStairs(n-2);
        dp[n] = ans;
        return dp[n];
    }
    // usig bottom up approch
    int solveusingBUApproch(int n, vector<int> & dp){
        dp[0]= 1;
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);
        //return solveusingTDApproch(n,dp);
        return solveusingBUApproch(n,dp);
        
    }
};