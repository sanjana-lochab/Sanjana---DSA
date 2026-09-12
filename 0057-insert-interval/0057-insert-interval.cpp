class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1;i<intervals.size();i++){
            int currentStart = intervals[i][0];
            int currentend = intervals[i][1];
            int lastend = ans.back()[1];
            if(lastend>=currentStart){
                ans.back()[1] = max(currentend,lastend);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};