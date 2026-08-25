class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        int ans;
        int maxi = 0;
        for(auto&[num,count]:mp){
            if(count>maxi){
                ans = num;
                maxi = max(maxi,count);
            }
        }
        return ans;
    }
};