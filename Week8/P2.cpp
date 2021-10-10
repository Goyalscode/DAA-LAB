
// using adjacency matrix representation

#include<iostream>
using namespace std;

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

void kruskals(int **graph, int V, int& sum)
{
    int parent[V];
    for(int i=0; i<V; i++)
        parent[i] = -1;
    for(int c=0; c<V-1; c++)
    {
        int min = INT_MAX;
        int u=-1, v=-1;
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(graph[i][j] && collapsingFind(parent, i) != collapsingFind(parent, j) && graph[i][j]<min)
                {
                    min = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        //cout<<u+1<<" "<<v+1<<"\n";
        unionByWeight(parent, u, v);
        sum += min;
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
    //cout<<"\n";
    kruskals(graph, V, sum);
    cout<<"Minimum Spanning Weight : "<<sum;
}

/*

// using another approach of input

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<pair<pair<int, int>, int>> viii;

int collapsingFind(int parent[], int u)
{
    if(parent[u] < 0)
        return u;
    else
    {
        int p = collapsingFind(parent, parent[u]);
        parent[u] = p;
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

bool comparator(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second < b.second;
}

void kruskals(viii graph, int V, int& sum)
{
    int parent[V];
    for(int i=0; i<V; i++)
        parent[i] = -1;
    sort(graph.begin(), graph.end(), comparator);
    int E = graph.size();
    for(int i=0; i<E; i++)
    {
        int u = graph[i].first.first;
        int v = graph[i].first.second;
        if(collapsingFind(parent, u) != collapsingFind(parent, v))
        {
            //cout<<u+1<<" "<<v+1<<"\n";
            unionByWeight(parent, u, v);
            sum += graph[i].second;
        }
    }
}

int main()
{
    int V,E;
    cin>>V>>E;
    viii graph(E);
    int s, d, w;
    for(int i=0; i<E; i++)
    {
        cin>>s>>d>>w;
        graph.push_back({{s, d}, w});
    }
    //cout<<"\n";
    int sum = 0;
    kruskals(graph, V, sum);
    cout<<"Minimum Spanning Weight : "<<sum;
}

*/
