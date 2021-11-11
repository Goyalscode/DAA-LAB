//  Floyd-Warshall all pair shortest path algorithm

#include<iostream>
using namespace std;

void floydWarshall(int* graph[], int* res[], int V)
{
    for(int k=0; k<V; k++)
    {
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                // check if there is a smaller distance from vertex i to j by including another vertex in between
                if(res[i][k] != 1000000000 && res[k][j] != 1000000000 && (res[i][j] > (res[i][k] + res[k][j])))
                    res[i][j] = res[i][k] + res[k][j];
            }
        }
    }
}

int main()
{
    int V;
    cin>>V;
    int *graph[V], *res[V];
    for(int i=0; i<V; i++)
    {
        graph[i] = (int*)malloc(sizeof(int)*V);
        res[i] = (int*)malloc(sizeof(int)*V);
        for(int j=0; j<V; j++)
        {
            cin>>graph[i][j];
            res[i][j] = graph[i][j];
        }
    }

    floydWarshall(graph, res, V);
    cout<<"Shortest Distance Matrix :\n";
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
            if(res[i][j] == 1000000000)
                cout<<"INF ";
            else
                cout<<res[i][j]<<" ";
        cout<<"\n";
    }
}
