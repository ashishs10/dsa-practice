//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    // void dfs(int node, int vis[], vector<int> adjList[])
    // {
    //     vis[node] = 1;
    //     for (auto it : adjList[node])
    //     {
    //         if (!vis[it]) 
    //         {
    //             dfs(it, vis, adjList);
    //         }
    //     }
    // }
    void bfs(int start, int vis[], vector<int> adjList[])
    {
        //marked visited for the nodes
        vis[start] = 1;
        
        queue<int> q; 
        q.push(start);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it : adjList[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjList[V];
        
        for (int i = 0; i < V; i++ )
        {
            for (int j = 0; j < V; j++)
            {
                if( adj[i][j] == 1 && i!=j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        int vis[V] = {0};
        int count = 0;
        
        for(int i = 0; i < V; i++ )
        {
            if (!vis[i])
            {
                count++;
                bfs(i, vis, adjList);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends