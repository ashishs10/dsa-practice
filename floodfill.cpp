//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:

    bool isValid(int row, int col, vector<vector<int>> &ans, int initialColor, int newColor )
    {
        int m = ans.size();
        int n = ans[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n ) return false;
        if (ans[row][col] == newColor) return false;
        if (ans[row][col] != initialColor) return false;
        return true;
        
    }
    void dfsFloodFill(vector<vector<int>> &ans, vector<pair <int, int>>&padosi,
    int sr, int sc, int newColor, int initialColor)
    {
        ans[sr][sc] = newColor;
        
        for (auto it : padosi)
        {
            int newRow = it.first + sr;
            int newCol = it.second + sc;
            if (isValid(newRow, newCol, ans, initialColor, newColor))
            {
                dfsFloodFill(ans, padosi, newRow, newCol, newColor, initialColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int initialColor = image[sr][sc];
        
        vector<vector<int>> ans = image;
        
        vector< pair <int, int>> padosi = {{-1,0}, {1,0},{0,-1},{0,1}};
        
        dfsFloodFill(ans, padosi, sr, sc, newColor, initialColor);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends