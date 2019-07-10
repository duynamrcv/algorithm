#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V; // no. of vertices

    // poiter to an array containing adjacency lists
    list<int> *adj;

    // a recursive function used by dfs
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V); // constructor

    // add an edge to graph
    void addEdge(int v, int w);
    
    // DFS traversal of the vertices reachable from v
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // add w to v's list
}

void Graph::DFSUtil(int v, bool visited[])
{
    // mark the current node as visted and print it
    visited[v] = true;
    cout << v << " ";

    // recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i]) DFSUtil(*i, visited);
    }
}

// DFS traversal of the vertices reachable from v. use recursive DFSUtil()
void Graph::DFS(int v)
{
    // mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) visited[i] = false;

    // call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}

int main()
{
    // create a graph  given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "DFS: ";
    g.DFS(2);
    cout << endl;
    return 0;
}