class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = nums[0];
        int maxi = nums[0];
        for(int i = 1;i<nums.size();i++){
            current = max(nums[i],nums[i]+current);
            maxi = max(current,maxi);
        }
        return maxi;
    }
};