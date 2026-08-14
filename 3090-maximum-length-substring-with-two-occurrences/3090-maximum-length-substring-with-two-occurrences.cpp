class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int right = 0;
        int max_len = 0;
        unordered_map<char,int> mp;
        for(int i = 0;i<s.length();i++){
            mp[s[right]]++;
            while(mp[s[right]]>2){
                mp[s[left]]--;
                left++;
            }
            right++;
            max_len = max(max_len,right-left);
        }
        return max_len;
    }
};