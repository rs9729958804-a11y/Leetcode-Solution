class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        // dp[i] stores all possible jump sizes
        // that can be used to reach stone i
        vector<unordered_set<int>> dp(n);

        // Frog starts at stone 0
        dp[0].insert(0);

        // Map stone position to its index
        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[stones[i]] = i;
        }

        for (int i = 0; i < n; i++) {

            for (int jump : dp[i]) {

                // Try jump-1, jump, jump+1
                for (int nextJump = jump - 1;
                     nextJump <= jump + 1;
                     nextJump++) {

                    if (nextJump <= 0)
                        continue;

                    int nextPosition = stones[i] + nextJump;

                    // Check if a stone exists at this position
                    if (pos.find(nextPosition) != pos.end()) {

                        int nextIndex = pos[nextPosition];

                        // We reached the last stone
                        if (nextIndex == n - 1)
                            return true;

                        // Store this possible jump
                        dp[nextIndex].insert(nextJump);
                    }
                }
            }
        }

        return false;
    }
};