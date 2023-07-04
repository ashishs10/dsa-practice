#include<bits/stdc++.h>

using namespace std;

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    
    // array of vectors to store graph 
    vector<int>adjList[nodes];

    //to store undirected graph
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

   for (int i = 0; i < nodes; i++) {
        cout << i << " -> ";
        for (int& x : adjList[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    
}