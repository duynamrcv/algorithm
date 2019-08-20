#include <iostream>

#define V 9
#define INT16_MAX 32767

using namespace std;

// find vertex with minimum distance
int minDistance(int dist[], bool sptSet[])
{
    int min = INT16_MAX;
    int min_index;
    for(int v = 0; v < V; v++)
    {
        if(!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// print the contructed distance array
void printSolution(int dist[], int n)
{
    cout << "Vertex:\t\tDistance from source:\n";
    for(int i = 0; i < V; i++)
    {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

// dijkstra
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // hold distance from src to i
    bool sptSet[V];

    // set all distance as INF and aptSet[] as false
    for(int i = 0; i< V; i++)
    {
        dist[i] = INT16_MAX;
        sptSet[i] = false;
    }

    // distance from src as 0;
    dist[src] = 0;

    // find shortest path
    for(int count = 0; count < V-1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        
        for(int v = 0; v < V; v++)
        {
            if(!sptSet[v] && graph[u][v] && dist[u] != INT16_MAX && dist[u]+graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);
}

int main()
{
    int graph[V][V] = { {0, 4,  0,  0,  0,  0,  0,  8,  0}, 
                        {4, 0,  8,  0,  0,  0,  0,  11, 0}, 
                        {0, 8,  0,  7,  0,  4,  0,  0,  2}, 
                        {0, 0,  7,  0,  9,  14, 0,  0,  0}, 
                        {0, 0,  0,  9,  0,  10, 0,  0,  0}, 
                        {0, 0,  4,  14, 10, 0,  2,  0,  0}, 
                        {0, 0,  0,  0,  0,  2,  0,  1,  6}, 
                        {8, 11, 0,  0,  0,  0,  1,  0,  7}, 
                        {0, 0,  2,  0,  0,  0,  6,  7,  0}}; 
   
    dijkstra(graph, 0); 
   
    return 0; 
}