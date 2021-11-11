//  Minimum cost to merge all elements of an array

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

long long int merge(int arr[], int n)
{
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0; i<n; i++)
        pq.push(arr[i]);
    long long int cost = 0;
    while(pq.size() > 1) // as we need at leat 2 files to merge
    {
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();
        cost += s1+s2;
        //cout<<cost<<"\n";
        pq.push(s1+s2); // push cost of merging into heap
    }
    return cost;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    long long int ans = merge(arr, n);
    cout<<ans<<"\n";
}
