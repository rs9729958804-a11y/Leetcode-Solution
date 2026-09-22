class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = 0;
        
        for(int x : nums) {
            maxNum = max(maxNum, x);
        }
        
        vector<int> points(maxNum + 1, 0);
        
        for(int x : nums) {
            points[x] += x;
        }
        
        vector<int> dp(maxNum + 1, 0);
        
        dp[0] = 0;
        dp[1] = points[1];
        
        for(int i = 2; i <= maxNum; i++) {
            
            dp[i] = max(dp[i - 1],
                        dp[i - 2] + points[i]);
        }
        
        return dp[maxNum];
    }
};