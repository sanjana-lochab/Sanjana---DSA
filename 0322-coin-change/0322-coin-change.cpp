class Solution {
public:
    // int solveusingRec(vector<int>& coins, int amount){
    //     // base case
    //     if(amount==0) return 0;

    //     // iss amount ko create krne ke liye 
    //     //i will try each and every coin
    //     int mini = INT_MAX;
    //     for(int i = 0;i<coins.size();i++){
    //         if(coins[i]<=amount){
    //             //valid case
    //             // maine ek coin use karliya
    //             int recursionkaAns = solveusingRec(coins,amount-coins[i]);
    //             // recursion ka answer can be valid or invalid
    //             if(recursionkaAns!=INT_MAX){
    //                 //ek valid ans 
    //                 //it amy or maynot be a minimum answer
    //                 mini = min(mini,1+recursionkaAns);   
    //             }

    //         }
    //     }
    //     return mini;
    // }
    //rec+memoization
    // int solveusingTopDown(vector<int>& coins, int amount,vector<int> dp){
    //     // base case
    //     if(amount==0) return 0;
    //     if(dp[amount]!=-1) return  dp[amount];
    //     // iss amount ko create krne ke liye 
    //     //i will try each and every coin
    //     int mini = INT_MAX;
    //     for(int i = 0;i<coins.size();i++){
    //         if(coins[i]<=amount){
    //             //valid case
    //             // maine ek coin use karliya
    //             int recursionkaAns = solveusingTopDown(coins,amount-coins[i],dp);
    //             // recursion ka answer can be valid or invalid
    //             if(recursionkaAns!=INT_MAX){
    //                 //ek valid ans 
    //                 //it amy or maynot be a minimum answer
    //                 mini = min(mini,1+recursionkaAns);   
    //             }

    //         }
    //     }
    //     dp[amount] = mini;
    //     return mini;
    // }
    //solve using tabulation method
    int solveusingTab(vector<int>& coins, int amount){
        vector<int> dp(amount+1,INT_MAX); //dafault is int_max
        //step 2:analyse
        dp[0] = 0;
        //step3: for loop ,reverse flow,copy paste,looping variable, replace function calls
        for(int value= 1;value<=amount;value++){
            int mini = INT_MAX;
            for(int j =0;j<coins.size();j++){
                if(coins[j]<=value){
                    int recursionKaAns = dp[value-coins[j]];

                    if(recursionKaAns!=INT_MAX){
                        mini = min(mini,1+recursionKaAns);
                    }
                }
            }
            dp[value] = mini;
        }
        //step 4
        return dp[amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int>dp(n+1,-1);
        // int ans = solveusingRec(coins,amount);
        // int ans = solveusingTopDown(coins,amount,dp);
        int ans = solveusingTab(coins,amount);
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};