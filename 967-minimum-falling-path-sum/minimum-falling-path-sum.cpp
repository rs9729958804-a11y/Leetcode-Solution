class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // First row
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Remaining rows
        for (int i = 1; i < n; i++) {

            for (int j = 0; j < n; j++) {

                int up = dp[i - 1][j];

                int left = INT_MAX;
                if (j > 0) {
                    left = dp[i - 1][j - 1];
                }

                int right = INT_MAX;
                if (j < n - 1) {
                    right = dp[i - 1][j + 1];
                }

                dp[i][j] = matrix[i][j] +
                           min(up, min(left, right));
            }
        }

        // Minimum value in last row
        int answer = INT_MAX;

        for (int j = 0; j < n; j++) {
            answer = min(answer, dp[n - 1][j]);
        }

        return answer;
    }
};