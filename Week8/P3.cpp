//  maximum spanning weight problem

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct graph_Edge
{
    int v1, v2;
    int w;
    graph_Edge(int vertex1, int vertex2, int weight)
    {
        w = weight;
        v1 = vertex1;
        v2 = vertex2;
    }
};

int collapsingFind(int parent[], int i)
{
    if(parent[i] < 0)
        return i;
    else
    {
        int p = collapsingFind(parent, parent[i]);
        parent[i] = p;
        return p;
    }
}

void unionByWeight(int parent[], int u, int v)
{
    int pu = collapsingFind(parent, u);
    int pv = collapsingFind(parent, v);
    if(pu != pv)
    {
        if(parent[pu] < parent[pv])
        {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else
        {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}

bool compare(graph_Edge a, graph_Edge b)
{
    return a.w > b.w;
}

void kruskals(int **graph, int V, int& sum)
{
    vector<graph_Edge>graph_edges;
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            if(graph[i][j] != 0)
            {
                graph_edges.push_back(graph_Edge(i, j, graph[i][j]));
            }
        }
    }
    sort(graph_edges.begin(), graph_edges.end(), compare);
    int E = graph_edges.size();
    int parent[V];
    for(int i=0; i<V; i++)
        parent[i] = -1;
    for(int i=0; i<E; i++)
    {
        int u = graph_edges[i].v1;
        int v = graph_edges[i].v2;
        if(collapsingFind(parent, u) != collapsingFind(parent, v))
        {
            unionByWeight(parent, u, v);
            sum += graph_edges[i].w;
        }
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
    int sum = 0;
    kruskals(graph, V, sum);
    cout<<"Maximum Spanning Weight : "<<sum;
}
