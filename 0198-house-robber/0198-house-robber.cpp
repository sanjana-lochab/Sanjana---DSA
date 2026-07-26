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
    //using bottom up approch
    int solveusingbottomupapproch(vector<int>& nums,vector<int>& dp,int i ){
        // base case
        dp[nums.size()] = 0;
        for(int i =nums.size()-1;i>=0;i--){
            int temp = 0;
            if(i+2<=nums.size()-1){
                 temp = dp[i+2];
            }
            
            int include = nums[i]+ temp;
            int exclude = 0 +dp[i+1];
            dp[i] = max(include, exclude);
        }
        return dp[0];
    }
    //using space optimization approch
    int spaceOptimization(vector<int>& nums,int i ){
        // base case
        int next1=0;
        int next2 = 0;
        int curr;
        for(int i =nums.size()-1;i>=0;i--){
            int temp = 0;
            if(i+2<=nums.size()-1){
                 temp = next2;
            }
            
            int include = nums[i]+ temp;
            int exclude = 0 +next1;
            curr = max(include, exclude);

            // ye main bhul jati hu
            next2 = next1;
            next1= curr;
            
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int i = 0;
        //return solve(nums,i);
        // top dowm approch
        vector<int> dp(nums.size()+1,-1);
        //return solveusingtopdownapproch(nums,dp,i);
        // return solveusingbottomupapproch(nums,dp,i);
        return spaceOptimization(nums,i);
    }
};