/* Given a graph, design an algorithm and implement it using a program to find
   if a graph is bipartite or not. */


#include<iostream>
#include<queue>
using namespace std;

bool checkBipartite(int* graph, int V, int* visited)
{
    queue<int>q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        if(*(graph+s*V+s) != 0)
            return false;
        int current = visited[s];
        for(int i=0; i<V; i++)
        {
            if(*(graph+s*V+i) == 1)
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = current * -1;
                }
                else if(visited[i] == current)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int V;
    cin>>V;
    int* graph = new int[V*V];
    int num;
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            cin>>num;
            *(graph+i*V+j) = num;
        }
    }
    int* visited = new int[V];
    for(int i=0; i<V; i++)
        visited[i] = 0;
    bool b = checkBipartite(graph, V, visited);
    if(b)
        cout<<"Yes Bipartite";
    else
        cout<<"Not Bipartite";
}
