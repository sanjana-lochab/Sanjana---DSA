class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i = k;
        int j = 0;
        while(j<nums.size()){
            if(i==nums[j]){
                i = i+k;
                j++;
            }
            else if(nums[j]<i){
                j++;
            }
            else{
                return i;
            }
        }
        return i;
    }
};