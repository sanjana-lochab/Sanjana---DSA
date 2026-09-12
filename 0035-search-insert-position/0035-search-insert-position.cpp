class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(target>nums[mid]){
               ans = mid;
                s = mid+1;
            }
            else if(target==nums[mid]) return mid;
            else e = mid-1;
        }
        return ans+1;
    }
};