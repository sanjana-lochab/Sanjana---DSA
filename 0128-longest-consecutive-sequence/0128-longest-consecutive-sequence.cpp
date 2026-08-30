class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        
        int maxi = 0;
        for(int num:st){
            if(st.find(num-1)==st.end()){
                int current = num;
                int length = 1;
                while(st.find(current+1)!=st.end()){
                    length++;
                    current++;
                }
                maxi = max(maxi,length);
            }
        }
        return maxi;
    }
};