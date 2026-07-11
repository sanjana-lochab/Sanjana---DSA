class Solution {
public:
    int answithdp(int n ,vector<int> & dp){
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]!=-1){
            return dp[n];
        }
        int  ans  = answithdp(n-1,dp)+answithdp(n-2,dp);
        dp[n]=ans;
        return dp[n];

    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return answithdp(n,dp);
    }
};