//  weight of the shortest path from source to destination with exactly k edges

#include<iostream>
using namespace std;

int find(int**graph, int V, int s, int d, int k)
{
    int t[V][V][k+1];  // t[s][d][k] means shortest path weight from s to d with exactly k edges
    for(int edge = 0; edge<=k; edge++)
    {
        for(int s = 0; s<V; s++)
        {
            for(int d = 0; d<V; d++)
            {
                t[s][d][edge] = INT_MAX;
                if(edge == 0)
                {
                    if(s == d)
                        t[s][d][edge] = 0; // if same vertex then weight is 0 to go to it
                }
                else if(edge == 1)
                {
                    if(graph[s][d] != 0)
                        t[s][d][edge] = graph[s][d];
                }
                else
                {
                    for(int adj_edge = 0; adj_edge<V; adj_edge++)
                    {
                        // k length path from s to d =
                        // weight of k-1 shortest path length from an adjacent edge of s to d + weight of path from s to that adjacent edge

                        if(adj_edge != s && adj_edge != d && graph[s][adj_edge] != 0 && t[adj_edge][d][k-1] != INT_MAX)
                        {
                            int adj_to_d = t[adj_edge][d][k-1];
                            int s_to_adj =  graph[s][adj_edge];
                            //cout<<adj_to_d + s_to_adj<<endl;
                            t[s][d][k] = min(t[s][d][k], adj_to_d + s_to_adj);
                        }
                    }
                }
            }
        }
    }
    return t[s][d][k]; // means shortest path from s to d with k edges in between
}

int main()
{
    int V;
    cin>>V;
    int **graph = (int**)malloc(sizeof(int*) * V);
    for(int i=0;i<V; i++)
    {
        graph[i] = (int*)malloc(sizeof(int)*V);
        for(int j=0; j<V;j++)
        {
            cin>>graph[i][j];
        }
    }
    int s, d;
    cin>>s>>d;
    int k;
    cin>>k;
    int ans = find(graph, V, s-1, d-1, k);
    if(ans == INT_MAX)
        cout<<"no path of length "<<k<<" is available\n";
    else
        cout<<"Weight of shortest path from ("<<s<<", "<<d<<") with "<<k<<" edges : "<<ans<<"\n";
}
