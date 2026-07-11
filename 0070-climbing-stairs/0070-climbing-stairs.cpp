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
        if(n==0) return 1;
        if(n==1) return 1;
        int prev2 = 1;
        int prev1 = 1;
        int curr = -1;
        for(int i = 2;i<=n;i++){
            curr= prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    int climbStairs(int n) {
        
        vector<int> dp(n+1,-1);
        //return solveusingTDApproch(n,dp);
        return solveusingBUApproch(n,dp);
        
    }
};