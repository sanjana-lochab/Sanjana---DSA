class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        int last1;
        int last2;
        for(int i = 0;i<n;i++){
            if(arr1.empty()){
                arr1.push_back(nums[i]);
                last1 = nums[i];
                continue;
            }
            if(arr2.empty()){
                arr2.push_back(nums[i]);
                last2 = nums[i];
                continue;
            }
            if(last1>last2){
                arr1.push_back(nums[i]);
                last1 =  nums[i];
            }
            else{
                arr2.push_back(nums[i]);
                last2 = nums[i];
            }
        }
        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};