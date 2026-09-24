class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        // Odd sum cannot be divided equally
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;

        vector<bool> dp(target + 1, false);

        // Sum 0 is always possible
        dp[0] = true;

        for (int num : nums) {

            // Traverse backwards
            for (int sum = target; sum >= num; sum--) {

                dp[sum] = dp[sum] || dp[sum - num];
            }
        }

        return dp[target];
    }
};