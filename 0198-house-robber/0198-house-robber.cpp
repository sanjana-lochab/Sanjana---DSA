class Solution {
public:
    // by recursion
    int solve(vector<int> & nums,int i){
        // base case
        if(i>=nums.size()) return 0;
        return max(nums[i]+solve(nums,i+2),solve(nums,i+1));
    }
    // by top down approch
    int solveusingtopdownapproch(vector<int>& nums,vector<int>& dp,int i ){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = max(nums[i]+solveusingtopdownapproch(nums,dp,i+2),solveusingtopdownapproch(nums,dp,i+1));
        dp[i] = ans;
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int i = 0;
        //return solve(nums,i);
        // top dowm approch
        vector<int> dp(nums.size()+1,-1);
        return solveusingtopdownapproch(nums,dp,i);
    }
};