#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>>& heights, int i, int j,
             vector<vector<bool>>& vis) {

        int n = heights.size();
        int m = heights[0].size();

        vis[i][j] = true;

        for(int k = 0; k < 4; k++) {

            int r = i + x[k];
            int c = j + y[k];

            if(r >= 0 && r < n &&
               c >= 0 && c < m &&
               !vis[r][c] &&
               heights[r][c] >= heights[i][j]) {

                dfs(heights, r, c, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        if(n == 0) return {};

        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific Ocean: First row and first column
        for(int i = 0; i < n; i++)
            dfs(heights, i, 0, pacific);

        for(int j = 0; j < m; j++)
            dfs(heights, 0, j, pacific);

        // Atlantic Ocean: Last row and last column
        for(int i = 0; i < n; i++)
            dfs(heights, i, m - 1, atlantic);

        for(int j = 0; j < m; j++)
            dfs(heights, n - 1, j, atlantic);

        vector<vector<int>> ans;

        // Find cells reachable by both oceans
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    vector<vector<int>> result = obj.pacificAtlantic(heights);

    cout << "Cells that can flow to both oceans:" << endl;

    for(auto cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "]" << endl;
    }

    return 0;
}