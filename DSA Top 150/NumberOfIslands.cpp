#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    
    bool validate(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        return true;
    }

    void dfs(vector<vector<char>> &a, int i, int j, int n, int m, vector<vector<bool>>& vis){
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            int row = i+x[k];
            int col = j+y[k];
            if(validate(row,col, n, m) && a[row][col]=='1' && vis[row][col]==0){
                dfs(a, row,col,n,m,vis);
            }
        }
    }

    int numIslands(vector<vector<char>> &a){
        int n = a.size();
        if(n==0){
            return 0;
        }
        int m = a[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m; j++){
                if(a[i][j]=='1' && vis[i][j]==0){
                    res++;
                    dfs(a,i,j,n,m,vis);
                }
            }
        }
        return res;
    }
};
int main() {
    Solution obj;

    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    cout << "Number of Islands: "
         << obj.numIslands(grid) << endl;

    return 0;
}