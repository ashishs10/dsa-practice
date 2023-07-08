//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        //mark the cell visited
        vis[row][col] = 1;
        queue<pair<int, int>>q;
        q.push({row, col});
        
        
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            //checking neighbours
            for ( int i = -1 ; i <= 1; i++ )
            {
                for ( int j = -1; j <= 1; j++ )
                {
                    int nrow = i + row;
                    int ncol = j + col;
                    if (isValid(nrow, ncol, vis, grid, m, n))
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }        
    }
  
    bool isValid(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&grid, int m, int n)
    {
        // if the rows and col are not valid
        if( row < 0 || row >= m || col < 0 || col >= n ) return false;
        if ( vis[row][col] ) return false;
        if ( grid[row][col] != '1') return false;
        return true;
    }
    
   
  
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int totalRow = grid.size();
        int totalCol = grid[0].size();
        
        vector< vector<int>> vis(totalRow, vector<int>(totalCol, 0));
        
        
        int count = 0;
        
        for ( int row = 0; row < totalRow; row++ )
        {
            for ( int col = 0; col < totalCol; col++ )
            {
                if (!vis[row][col] & grid[row][col]=='1')
                {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends