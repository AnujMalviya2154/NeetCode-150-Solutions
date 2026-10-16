class Solution {
public:
    void dfs(int r, int c, set<pair<int,int>>& visit, int prevHeight, vector<vector<int>>& heights){
        int rows = heights.size();
        int cols = heights[0].size();
        
        if(r<0 || c<0 || r>=rows || c>=cols || visit.count({r,c})||heights[r][c]<prevHeight) return;
    
        visit.insert({r,c});

        dfs(r + 1, c, visit, heights[r][c], heights);
        dfs(r - 1, c, visit, heights[r][c], heights);
        dfs(r, c + 1, visit, heights[r][c], heights);
        dfs(r, c - 1, visit, heights[r][c], heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int rows = heights.size();
        int cols = heights[0].size();

        set<pair<int, int>> pac, atl;

        for(int c=0;c<cols;c++){
            dfs(0,c,pac,heights[0][c],heights);
            dfs(rows-1,c,atl,heights[rows-1][c],heights);
        }
        for (int r = 0; r < rows; r++) {
            dfs(r, 0, pac, heights[r][0], heights);
            dfs(r, cols - 1, atl, heights[r][cols - 1], heights);
        }

        vector<vector<int>>res;
         for (auto cell : pac) {
            if (atl.count(cell)) {
                res.push_back({cell.first, cell.second});
            }
        }

        return res;
    }
};
