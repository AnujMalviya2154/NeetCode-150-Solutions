class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c) {

        int rows = grid.size();
        int cols = grid[0].size();

        // Outside the grid
        if(r < 0 || r >= rows || c < 0 || c >= cols)
            return 0;

        // Water or already visited
        if(grid[r][c] == 0)
            return 0;

        // Mark current cell as visited
        grid[r][c] = 0;

        // Current cell contributes 1 to the area
        int area = 1;

        // Visit all 4 directions
        area += dfs(grid, r - 1, c); // up
        area += dfs(grid, r + 1, c); // down
        area += dfs(grid, r, c - 1); // left
        area += dfs(grid, r, c + 1); // right

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int maxArea = 0;

        // Scan the entire grid
        for(int r = 0; r < rows; r++) {

            for(int c = 0; c < cols; c++) {

                if(grid[r][c] == 1) {

                    int area = dfs(grid, r, c);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};