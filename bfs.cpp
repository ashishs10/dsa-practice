#include<bits/stdc++.h>

using namespace std;

vector<int> bfsTraversal(int nodes, vector<int> adj[])
{
    //initial configuration for the traversal
    int visitedNodes[nodes] ={0}; // since the initial node is 0, [nodes + 1] if initial node 1
    visitedNodes[0] = 1; // marking the initial node a visited
    queue<int> q;
    q.push(0); //pushing the initial node into the queue

    //a vector to store the traversed nodes
    vector<int> bfsList;

    //check if the queue is empty
    while ( !q.empty())
    {
        int node = q.front();
        q.pop();
        bfsList.push_back(node);

        //check if the neighbours are visited, if not mark them visited and push them in queue
        for (auto it : adj[node])
        {
            if (!visitedNodes[it])
            {
                visitedNodes[it] = 1;
                q.push(it);
            }
        }
    }
    return bfsList;
}

void printList(vector<int>&a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<int>adj[nodes];

    //storing graphs in adjacency list
    for (int i = 0; i < edges; i++ )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bfs = bfsTraversal(nodes, adj);
    printList(bfs);




}