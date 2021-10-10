
// using adjacency matrix representation

#include<iostream>
using namespace std;
#define INF 1000000000

void printMST(int parent[], int V)
{
    for(int i=1; i<V; i++)
        cout<<parent[i]+1<<" "<<i+1<<"\n";
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

void prims(int **graph, int V, int& sum)
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
    dist[0] = 0;
    while(tot < V)
    {
        int u = findMin(V, dist, processed);
        processed[u] = 1;
        sum += dist[u];
        tot++;
        //if(tot == V-1)
            //break;
        for(int i=0; i<V; i++)
        {
            if(!processed[i] && graph[u][i] && dist[u] != INF && (dist[i] > graph[u][i]))
            {
                dist[i] = graph[u][i];
                parent[i] = u;
            }
        }
    }
    //cout<<"\n";
    //printMST(parent, V);
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
    int sum = 0;
    prims(graph, V, sum);
    cout<<"Minimum Spanning Weight : "<<sum;
}

/*

// using adjacency list representation

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

void printMST(int *parent, int V)
{
    for(int i=1; i<V; i++)
        cout<<parent[i]+1<<" "<<i+1<<"\n";
}

void prims(vii graph[], int V, int& sum)
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
    dist[0] = 0;
    priority_queue<pii, vector<pii>, compare>pq;
    pq.push({0, 0});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(processed[u])
            continue;
        sum += dist[u];
        processed[u] = true;
        int s = graph[u].size();
        for(int i=0; i<s; i++)
        {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;
            if(!processed[v] && (dist[v] > weight))
            {
                dist[v] = weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    //cout<<"\n";
    //printMST(parent, V);
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
        graph[s].push_back({d, w});
    }
    int sum = 0;
    prims(graph, V, sum);
    cout<<"Minimum Spanning Weight : "<<sum;
}

*/

