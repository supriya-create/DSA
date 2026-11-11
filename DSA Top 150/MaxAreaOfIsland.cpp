#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {

        int n = grid.size();
        int m = grid[0].size();

        // Boundary condition
        if(i < 0 || i >= n || j < 0 || j >= m ||
           grid[i][j] == 0) {
            return 0;
        }

        // Mark visited
        grid[i][j] = 0;

        // Count current cell
        int area = 1;

        // Explore four directions
        area += dfs(grid, i + 1, j);
        area += dfs(grid, i - 1, j);
        area += dfs(grid, i, j + 1);
        area += dfs(grid, i, j - 1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        if(n == 0) return 0;

        int m = grid[0].size();
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {

                    int area = dfs(grid, i, j);

                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1}
    };

    cout << "Maximum Area of Island: "
         << obj.maxAreaOfIsland(grid) << endl;

    return 0;
}