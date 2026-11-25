class Solution {
public:
    int trap(vector<int>& height) {
        int ans= 0;
        int n = height.size();
        int leftmax[20000];
        int rightmax[20000];
        leftmax[0] = 0;
        for(int i = 1;i<n;i++){
            leftmax[i] = max(leftmax[i-1],height[i-1]);
        }
        //for right max
        rightmax[n-1] = 0;
        for(int i = n-2;i>=0;i--){
            rightmax[i] = max(rightmax[i+1],height[i+1]);
        }
        for(int i = 0;i<n;i++){
            ans+= max(0,min(leftmax[i],rightmax[i]) - height[i]);
        }
        return ans;
    }
};