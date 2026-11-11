#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        if (n == 0) return 0;

        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Store rotten oranges and count fresh oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = -2;
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;

        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};

        // Multi-source BFS
        while(!q.empty() && fresh > 0) {

            int s = q.size();
            time++;

            while(s--) {

                pair<int, int> p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                for(int k = 0; k < 4; k++) {

                    int row = r + x[k];
                    int col = c + y[k];

                    if(row >= 0 && row < n &&
                       col >= 0 && col < m &&
                       grid[row][col] == 1) {

                        q.push({row, col});
                        grid[row][col] = -2;
                        fresh--;
                    }
                }
            }
        }

        return (fresh == 0) ? time : -1;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << "Minimum time required: "
         << obj.orangesRotting(grid) << endl;

    return 0;
}