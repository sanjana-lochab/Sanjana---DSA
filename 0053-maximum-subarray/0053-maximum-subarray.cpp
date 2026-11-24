class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int currsum = 0;
        for(int start = 0;start <n;start++){
            currsum += nums[start];
            maxi = max(maxi,currsum);
            if(currsum<0) currsum =0;
            
        }
        return maxi;
    }
};