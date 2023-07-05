#include <bits/stdc++.h>

using namespace std;

void dfsTraversal(int node, vector<int> adj[], int vis[], vector<int> &dfsList)
{
    /*
    Description: 
        This function performs a depth-first search (DFS) traversal 
        of the graph starting from the given node.

    Parameters:
        1. node : The starting node to start the traversal 
        2. adj : The adjacency list of the graph
        3. vis : a list to keep track of which nodes have been visited
        4. A lis to store the nodes in the order they were visited

    Returns:
        None
    */

    //mark the current node as visited
    vis[node] = 1;

    //add the current node to the list of visited nodes
    dfsList.push_back(node);

    // traverse all the neighbours of the node and recursively
    // the dfsTraversal function on all the neighbours of the 
    // current node that have not been visited yet
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
    /*
    Description:
        This performs a depth-first search (DFS) traversal of
        the graph and returns a list of the nodes in the order
        they were visited

    Parameters:
        1. nodes : The number of nodes in the graph
        2. adj : The adjacency list of the graph
        3. start : the to start the traversal from.

    Returns: 
        A list of the nodes in the order they were visited
    */

    // visited array intially to 0s
    int visitedNodes[nodes + 1] = {0};                    
    
    vector<int> dfsList; // list to store the nodes in the order they are traversed
    //call the dfsTraversal function on the start node
    dfsTraversal(start, adj, visitedNodes, dfsList);

    //return the list of traversed list of nodes
    return dfsList;

}

vector<int> bfsTraversal(int nodes, vector<int> adj[], int start)
{

    /*
    Description:
        This function performs a breadth-first search (BFS) traversal 
        of the graph and returns a list of the nodes in the order they were visited.

    Parameters:
        1. nodes : The number of nodes in the graph
        2. adj : The adjacency list of the graph
        3. start : the to start the traversal from.

    Returns: 
        A list of the nodes in the order they were visited
    */

    // initialize a visited array to all 0s
    int visitedNodes[nodes + 1] = {0}; 
     // marking the initial node a visited and push into queue
    visitedNodes[start] = 1;          
    queue<int> q;
    q.push(start); // pushing the initial node into the queue

    // a vector to store the traversed nodes
    vector<int> bfsList;

    // while the queue is not empty
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