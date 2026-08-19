class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto&[num,count]:mp){
            if(count==1){
                return num;
            }
        }
        return -1;
    }
};