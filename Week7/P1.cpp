
// using adjacency matrix

#include<iostream>
using namespace std;
#define INF 1000000000

void printPath(int parent[], int V, int i)
{
    if(i == -1)
        return;
    else
    {
        cout<<i+1<<" ";
        printPath(parent, V, parent[i]);
    }
}

int findMin(int V, int dist[], int processed[])
{
    int min = INF, min_vertex = 0;
    for(int i=0; i<V; i++)
    {
        if(!processed[i])
        {
            if(dist[i]<min)
            {
                min_vertex = i;
                min = dist[i];
            }
        }
    }
    return min_vertex;
}

void dijkstras(int **graph, int V, int source)
{
    int parent[V];
    int dist[V];
    int processed[V];
    for(int i=0; i<V; i++)
    {
        parent[i] = -1;
        processed[i] = 0;
        dist[i] = INF;
    }
    int tot = 0;
    dist[source] = 0;
    while(tot < V-1)
    {
        int u = findMin(V, dist, processed);
        //cout<<u<<endl;
        processed[u] = 1;
        tot++;
        for(int i=0; i<V; i++)
        {
            if(!processed[i] && graph[u][i] && dist[u] != INF && (dist[i] > (dist[u] + graph[u][i])))
            {
                dist[i] = dist[u] + graph[u][i];
                parent[i] = u;
                //cout<<dist[i]<<endl;
            }
        }
    }
    cout<<"\n";
    for(int i=0; i<V; i++)
    {
        printPath(parent, V, i);
        cout<<" : "<<dist[i]<<"\n";
    }
}

int main()
{
    int V;
    cin>>V;
    int **graph = new int*[V];
    for(int i=0; i<V; i++)
    {
        graph[i] = new int[V];
        for(int j=0; j<V; j++)
            cin>>graph[i][j];
    }
    int source;
    cin>>source;
    dijkstras(graph, V, source-1);
}

/*

// using adjacency list

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1000000000
typedef pair<int,int> pii;
typedef vector<pair<int, int>> vii;

struct compare
{
    bool operator() (pii a, pii b)
    {
        return a.first > b.first; // for minheap
    }
};

void printPath(int *parent, int u)
{
    if(u==-1)
        return;
    cout<<u+1<<" ";
    printPath(parent, parent[u]);
}

void dijkstras(vii graph[], int V, int source)
{
    int *parent = new int[V];
    int *dist = new int[V];
    int *processed = new int[V];
    for(int i=0; i<V; i++)
    {
        dist[i] = INF;
        processed[i] = 0;
        parent[i] = -1;
    }
    dist[source] = 0;
    priority_queue<pii, vector<pii>, compare>pq;
    pq.push({dist[source], source});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(processed[u])
            continue;
        processed[u] = true;
        int s = graph[u].size();
        for(int i=0; i<s; i++)
        {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;
            if(!processed[v] && dist[u] != INF && (dist[v] > dist[u] + weight))
            {
                dist[v] = weight + dist[u];
                parent[v] = u;
                pq.push({dist[v], v});
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
    int s,d,w;
    for(int i=0; i<E; i++)
    {
        cin>>s>>d>>w;
        graph[s-1].push_back({d-1, w});
    }
    int source;
    cin>>source;
    dijkstras(graph, V, source-1);
}

*/
