class Solution {
public:
    int rows, cols;
    int total;
    int ans = 0;

    void dfs(int r, int c, int count, vector<vector<int>>& grid) {
        // Out of bounds or obstacle
        if (r < 0 || r >= rows || c < 0 || c >= cols ||
            grid[r][c] == -1) {
            return;
        }

        // Reached the ending square
        if (grid[r][c] == 2) {
            if (count == total)
                ans++;
            return;
        }

        // Mark current cell as visited
        grid[r][c] = -1;

        // Four possible directions
        dfs(r + 1, c, count + 1, grid);
        dfs(r - 1, c, count + 1, grid);
        dfs(r, c + 1, count + 1, grid);
        dfs(r, c - 1, count + 1, grid);

        // Backtrack
        grid[r][c] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int startR = 0, startC = 0;
        total = 0;

        // Find start and count all non-obstacle cells
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] != -1)
                    total++;

                if (grid[i][j] == 1) {
                    startR = i;
                    startC = j;
                }
            }
        }

        dfs(startR, startC, 1, grid);

        return ans;
    }
};