class Solution {
private:
    bool dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // If it goes out of bounds, it's not a closed island
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return false;
        }
        
        // If it's water (1), it's a valid boundary for the island
        if (grid[r][c] == 1) {
            return true;
        }
        
        // Mark the current land cell as visited by turning it into water (1)
        grid[r][c] = 1;
        
        // Visit all 4 directions
        bool left   = dfs(grid, r, c - 1);
        bool right  = dfs(grid, r, c + 1);
        bool top    = dfs(grid, r - 1, c);
        bool bottom = dfs(grid, r + 1, c);
        
        // An island is closed only if all 4 directions return true
        return left && right && top && bottom;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: Eliminate all 0s connected to the boundary by turning them into 1s
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    if (grid[r][c] == 0) {
                        // We can run a simple sink DFS on boundary lands
                        sinkBoundary(grid, r, c);
                    }
                }
            }
        }
        
        // Step 2: Count the remaining closed islands
        int closedIslandsCount = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    if (dfs(grid, r, c)) {
                        closedIslandsCount++;
                    }
                }
            }
        }
        
        return closedIslandsCount;
    }

private:
    void sinkBoundary(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }
        grid[r][c] = 1;
        sinkBoundary(grid, r + 1, c);
        sinkBoundary(grid, r - 1, c);
        sinkBoundary(grid, r, c + 1);
        sinkBoundary(grid, r, c - 1);
    }
};
