/*  Given a set of available types of coins. Let suppose you have infinite supply of each type of coin.
    For a given value N, you have to Design an algorithm and implement it using a program to find
    number of ways in which these coins can be added to make sum value equals to N.  */

#include<iostream>
using namespace std;

int find(int coins[], int n, int N)
{
    int t[n+1][N+1];
    for(int i=1; i<N+1; i++)
        t[0][i] = 0;            // if coins are 0, no way to get upto N>=1
    for(int i=0; i<n+1; i++)
        t[i][0] = 1;            // if N=0, one way by inclusing no coin
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<N+1; j++)
        {
            int inc_ways;
            if(j >= coins[i-1])
                inc_ways = t[i][j-coins[i-1]];  // taking i as we can include coin any no of times
            else
                inc_ways = 0;
            int exc_ways = t[i-1][j];
            t[i][j] = inc_ways + exc_ways;
        }
    }
    return t[n][N];
}

int main()
{
    int n;
    cin>>n;
    int coins[n];
    for(int i=0; i<n; i++)
        cin>>coins[i];
    int N;
    cin>>N;
    int ways = find(coins, n, N);
    cout<<ways<<"\n";
}
