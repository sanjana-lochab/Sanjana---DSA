class Solution {
public:
    int firstindex(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int ans = -1;
        while(start<=end){
            int mid =start +(end-start)/2;
            if(target>nums[mid]) start= mid+1;
            else if(target<nums[mid]) end = mid-1;
            else {
                ans = mid;
                end = mid-1;
            }
        }
        return ans;
    }
    int lastindex(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size()-1;
        int ans = -1;
        while(start<=end){
            int mid =start +(end-start)/2;
            if(target>nums[mid]) start= mid+1;
            else if(target<nums[mid]) end = mid-1;
            else {
                ans = mid;
                start = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstindex(nums,target);
        int last = lastindex(nums,target);
        vector<int> temp;
        temp.push_back(first);
        temp.push_back(last);
        return temp;
    }
};