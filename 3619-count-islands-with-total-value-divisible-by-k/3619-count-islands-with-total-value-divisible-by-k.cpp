class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        auto dfs = [&](auto& self, int r, int c) -> long long {
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
                return 0;
            }
            long long sum = grid[r][c];
            grid[r][c] = 0; // Mark as visited

            sum += self(self, r + 1, c);
            sum += self(self, r - 1, c);
            sum += self(self, r, c + 1);
            sum += self(self, r, c - 1);

            return sum;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long islandSum = dfs(dfs, i, j);
                    if (islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};