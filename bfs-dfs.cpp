#include <bits/stdc++.h>

using namespace std;

void dfsTraversal(int node, vector<int> adj[], int vis[], vector<int> &dfsList)
{
    vis[node] = 1;
    dfsList.push_back(node);

    // traverse all the neighbours of the node
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfsTraversal(it, adj, vis, dfsList);
        }
    }
}

vector<int> dfsGraph(int nodes, vector<int> adj[], int start)
{
    // visited array
    int visitedNodes[nodes + 1] = {0};
    vector<int> dfsList;
    dfsTraversal(start, adj, visitedNodes, dfsList);
    return dfsList;

}

vector<int> bfsTraversal(int nodes, vector<int> adj[], int start)
{
    // initial configuration for the traversal
    int visitedNodes[nodes + 1] = {0}; // since the initial node is 0, [nodes + 1] if initial node 1
    visitedNodes[start] = 1;           // marking the initial node a visited
    queue<int> q;
    q.push(start); // pushing the initial node into the queue

    // a vector to store the traversed nodes
    vector<int> bfsList;

    // check if the queue is empty
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfsList.push_back(node);

        // check if the neighbours are visited, if not mark them visited and push them in queue
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

// utility function to print graph
void printGraph(vector<int> adj[], int nodes)
{
    for (int i = 1; i < nodes; i++)
    {
        cout << i << " -> ";
        for (int &x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

// utility function to print traversed list
void printTraversalList(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int nodes, edges, startNode, choice;
    cout << "Enter the number of nodes in the graph: ";
    cin >> nodes;
    cout << "Enter the number of edges in the graph: ";
    cin >> edges;

    // creating adjacency list to store the graph
    vector<int> adjList[nodes + 1];

    // storing graphs in adjacency list, if the graph is undirected
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter the edge " << i + 1 << " : ";
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    do
    {
        cout << "1. BFS Traversal\n";
        cout << "2. DFS Traversal\n";
        cout << "3. Exit\n";
        cout << "Choose option: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
            case 1:
            {
                cout << "Enter the starting node: ";
                cin >> startNode;
                vector<int> bfs = bfsTraversal(nodes, adjList, startNode);
                cout << "The BFS traversal with starting node (" << startNode << ") : ";
                printTraversalList(bfs);
                cout << endl
                    << endl;
                break;
            }
            case 2:
            {
                cout << "Enter the starting node: ";
                cin >> startNode;
                vector<int> bfs = dfsGraph(nodes, adjList, startNode);
                cout << "The BFS traversal with starting node (" << startNode << ") : ";
                printTraversalList(bfs);
                cout << endl
                     << endl;
                break;
            }
            
            default: cout << "Enter the correct option.";
        }

    } while (choice != 3);
    // cout << "The graph : " << endl;
    // printGraph(adjList, nodes);
}