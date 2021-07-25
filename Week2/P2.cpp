/* Given a sorted array of positive integers, design an algorithm and implement it using a program to find
   three indices i, j, k such that arr[i] + arr[j] = arr[k].  */

#include<iostream>
using namespace std;

int Binary_search(int arr[], int l, int r, int s)
{
    while(l <= r)
    {
        int m = l+(r-l)/2;
        if(arr[m] == s)
            return m;
        else if(arr[m] < s)
            l = m+1;
        else
            r = m-1;
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++)
            cin>>arr[j];
        int st = 0;
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int l = Binary_search(arr, k+1, n-1, arr[j]+arr[k]);
                if(l!=-1)
                {
                    cout<<j+1<<","<<k+1<<","<<l+1<<"\n";
                    st = 1;
                    break;
                }
            }
            if(st)
                break;
        }
        if(!st)
            cout<<"No sequence found\n";
    }
}


// input and output file is accessed using input(<) and output(>) redirection operator respectively at execution time.
