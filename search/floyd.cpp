#include <iostream>
using namespace std;

#define V 4
#define INF 32767

void printFloyd(int dis[][V]);
void floyd(int graph[][V]);

int main()
{
    int graph[V][V] = { {0, 5, INF, 10},  
                        {INF, 0, 3, INF},  
                        {INF, INF, 0, 1},  
                        {INF, INF, INF, 0}  
                    };
    floyd(graph);
    return 0;
}

void floyd(int gragh[][V])
{
    int dis[V][V], i, j, k;
    for(i = 0; i < V; i++)
    {
        for(j = 0; j < V; j++)
        {
            dis[i][j] = gragh[i][j];
        }
    }

    for(k = 0; k < V; k++)
    {
        for(i = 0; i < V; i++)
        {
            for(j = 0; j < V; j++)
            {
                if(dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    printFloyd(dis);
}

void printFloyd(int dis[][V])
{
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(dis[i][j] == INF) cout << "INF\t";
            else cout << dis[i][j] << "\t";
        }
        cout << endl;
    }
}