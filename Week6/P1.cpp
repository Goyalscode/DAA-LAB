/* Given a (directed/undirected) graph, design an algorithm and implement it using
   a program to find if a path exists between two given vertices or not. */


#include<iostream>
using namespace std;

bool pathCheck(int* graph, int s, int d, int V, bool* visited)
{
    visited[s] = true;
    for(int i = 0; i < V; i++)
    {
        if(*(graph+(s*V)+i) == 1)
        {
            if(i == d)
                return true;
            if(!visited[i])
                return pathCheck(graph, i, d, V, visited);
        }
    }
    return false;
}

int main()
{
    int V;
    cin>>V;
    int *graph = new int[V*V];
    int s, d;
    int val;
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cin>>val;
            *(graph+i*V+j) = val;
        }
    }
    cin>>s>>d;
    bool* visited = new bool[V];
    for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }
    bool b = pathCheck(graph, s-1, d-1, V, visited);
    if(b)
        cout<<"Yes Path Exists";
    else
        cout<<"No Such Path Exists";
}
