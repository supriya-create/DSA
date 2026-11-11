
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        if(r < 0 || c < 0 || r >= n || c >= m ||
           board[r][c] != 'O') {
            return;
        }

        board[r][c] = '#';

        dfs(r+1, c, board);
        dfs(r-1, c, board);
        dfs(r, c+1, board);
        dfs(r, c-1, board);
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;

        int n = board.size();
        int m = board[0].size();

        // Check first and last columns
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O')
                dfs(i, 0, board);

            if(board[i][m-1] == 'O')
                dfs(i, m-1, board);
        }

        // Check first and last rows
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O')
                dfs(0, j, board);

            if(board[n-1][j] == 'O')
                dfs(n-1, j, board);
        }

        // Convert surrounded O to X
        // Restore safe O from #
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

int main() {
    Solution obj;

    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    obj.solve(board);

    cout << "Final Board:\n";

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
