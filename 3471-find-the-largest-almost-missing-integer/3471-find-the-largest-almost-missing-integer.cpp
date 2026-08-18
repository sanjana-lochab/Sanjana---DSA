class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = -1;
        unordered_map<int,int> freq;
        
        for(int i = 0;i<n;i++){
                freq[nums[i]]++;
            }      
        if(k==1){
            for(auto&[num,count]:freq){
                if(count==1){
                    maxi = max(maxi,num);
                }
            }
            return maxi;
        }
        else if(k==n){
            for(int i = 0;i<n;i++){
                maxi = max(maxi,nums[i]);
            }
            return maxi;
        }
        int ans = -1;

        if(freq[nums[0]] == 1)
            ans = max(ans, nums[0]);

        if(freq[nums[n-1]] == 1)
            ans = max(ans, nums[n-1]);

        return ans;
    }
};