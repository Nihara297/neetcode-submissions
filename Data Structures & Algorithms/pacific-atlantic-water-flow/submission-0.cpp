class Solution {
public:

    int m, n;

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& ocean,
             int r, int c) {

        ocean[r][c] = true;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= m ||
                nc < 0 || nc >= n)
                continue;

            if (ocean[nr][nc])
                continue;

            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(heights, ocean, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(
            m, vector<bool>(n, false));

        vector<vector<bool>> atlantic(
            m, vector<bool>(n, false));

        // Pacific
        for (int c = 0; c < n; c++) {
            dfs(heights, pacific, 0, c);
            dfs(heights, atlantic, m - 1, c);
        }

        for (int r = 0; r < m; r++) {
            dfs(heights, pacific, r, 0);
            dfs(heights, atlantic, r, n - 1);
        }

        vector<vector<int>> result;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (pacific[r][c] &&
                    atlantic[r][c]) {

                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};