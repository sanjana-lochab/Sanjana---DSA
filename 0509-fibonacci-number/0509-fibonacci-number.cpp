class Solution {
public:
//top -dowm approch
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
    //bottom up approch
    int solveusingTabulation(int n){ //if n = 0;line 27 will throw error
        // step 1 : create dp array
         vector<int> dp(n+1,-1);
         // step 2: analyse base case and fill dp array , so we will add if cases for them 
         if(n==0){
            return 0;
         }
         if(n==1){
            return 1;
         }
         dp[0] = 0;
         dp[1] = 1;
        //step 3: loop wala logic ,reverse the top-down flow
        for(int i =2;i<=n;i++){
            //copy-paste
            // skip base case,and already exist case, return statement
            //convert function call ko dp arrayme
            //looping variable sahi se replace krdena
            int  ans  = dp[i-1]+dp[i-2];
            dp[i]=ans;
        }
        //step 4 : return ans;
        return dp[n];
    }
    int solveusingTabulationSO(int n){ //if n = 0;line 27 will throw error
        // step 1 : create dp array
         //vector<int> dp(n+1,-1);
         
         
         // step 2: analyse base case and fill dp array , so we will add if cases for them 
         if(n==0){
            return 0;
         }
         if(n==1){
            return 1;
         }
         int prev2 = 0;
         int prev1 = 1;
         int curr = -1;
        //step 3: loop wala logic ,reverse the top-down flow
        for(int i =2;i<=n;i++){
            //copy-paste
            // skip base case,and already exist case, return statement
            //convert function call ko dp arrayme
            //looping variable sahi se replace krdena
            curr = prev1+prev2;
            // ye me pakka bhul jaugi
            prev2 = prev1;
            prev1 = curr;
            
        }
        //step 4 : return ans;
        return curr;
    }
   
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return solveusingTabulationSO(n);
    }
};