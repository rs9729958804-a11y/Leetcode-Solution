class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = minimum coins needed to make i
        vector<int> dp(amount + 1, amount + 1);

        // 0 coins are needed to make amount 0
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {

            for (int coin : coins) {

                if (coin <= i) {
                    dp[i] = min(dp[i],
                                dp[i - coin] + 1);
                }
            }
        }

        // If amount is still unreachable
        if (dp[amount] == amount + 1)
            return -1;
        
        return dp[amount];
    }
};