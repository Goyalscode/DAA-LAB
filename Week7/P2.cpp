
// using adjacency matrix

#include<iostream>
using namespace std;
#define INF 1000000000

void printPath(int parent[], int u)
{
    if(u == -1)
        return;
    cout<<u+1<<" ";
    printPath(parent, parent[u]);
}

void bellmanFord(int **graph, int V, int source)
{
    int dist[V];
    int parent[V];
    for(int i=0; i<V; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;
    for(int i=0; i<V-1; i++)
    {
        int status = 0;
        for(int j=0; j<V; j++)
        {
            for(int k=0; k<V; k++)
            {
                if(graph[j][k] == 0)
                    continue;
                int u = j;
                int v = k;
                int weight = graph[u][v];
                if(dist[u]!=INF && (dist[v] > dist[u] + weight))
                {
                    status = 1;
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
            }
        }
        if(status == 0)
            break;
    }

    for(int j=0; j<V; j++)
    {
        for(int k=0; k<V; k++)
        {
            if(graph[j][k] == 0)
                continue;
            int u = j;
            int v = k;
            int weight = graph[u][v];
            if(dist[u]!=INF && (dist[v] > dist[u] + weight))
            {
                cout<<"Negative Cycle Exists";
                return;
            }
        }
    }

    for(int i=0; i<V; i++)
    {
        printPath(parent, i);
        cout<<" : "<<dist[i]<<"\n";
    }
}

int main()
{
    int V;
    cin>>V;
    int **graph = new int*[V];
    int s, d, w;
    for(int i=0; i<V; i++)
    {
        graph[i] = new int[V];
        for(int j=0; j<V; j++)
            cin>>graph[i][j];
    }
    int source;
    cin>>source;
    bellmanFord(graph, V, source-1);
}

/*

// using adjacency list

#include<iostream>
#include<vector>
using namespace std;
#define INF 1000000000
typedef vector<pair<int, int>> vii;

void printPath(int parent[], int u)
{
    if(u == -1)
        return;
    cout<<u+1<<" ";
    printPath(parent, parent[u]);
}

void bellmanFord(vii graph[], int V, int source)
{
    int dist[V];
    int parent[V];
    for(int i=0; i<V; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;
    for(int i=0; i<V-1; i++)
    {
        int status = 0;
        for(int j=0; j<V; j++)
        {
            int s = graph[j].size();
            for(int k=0; k<s; k++)
            {
                int u = j;
                int v = graph[u][k].first;
                int weight = graph[u][k].second;
                if(dist[u]!=INF && (dist[v] > dist[u] + weight))
                {
                    status = 1;
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
            }
        }
        if(status == 0)
            break;
    }

    for(int j=0; j<V; j++)
    {
        int s = graph[j].size();
        for(int k=0; k<s; k++)
        {
            int u = j;
            int v = graph[u][k].first;
            int weight = graph[u][k].second;
            if(dist[u]!=INF && (dist[v] > dist[u] + weight))
            {
                cout<<"Negative Cycle Exists";
                return;
            }
        }
    }

    for(int i=0; i<V; i++)
    {
        printPath(parent, i);
        cout<<" : "<<dist[i]<<"\n";
    }
}

int main()
{
    int V, E;
    cin>>V>>E;
    vii graph[V];
    int s, d, w;
    for(int i=0; i<E; i++)
    {
        cin>>s>>d>>w;
        graph[s-1].push_back({d-1, w});
    }
    int source;
    cin>>source;
    bellmanFord(graph, V, source-1);
}

*/
