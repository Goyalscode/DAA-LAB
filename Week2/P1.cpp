/* Given a sorted array of positive integers containing few duplicate elements design an algorithm and implement it
   using a program to find whether the given key element is present in the array or not. If present, then also find the
   numer of copies of given key. (Time Complexity = O(log n)) */

#include<iostream>
using namespace std;

int lower(int arr[], int l, int r, int key)
{
    while(l <= r)
    {
        int m = l+(r-l)/2;
        if(arr[m] >= key)
            r = m-1;
        else
            l = m+1;
    }
    return l;
}

int upper(int arr[], int l, int r, int key)
{
    while(l <= r)
    {
        int m = l+(r-l)/2;
        if(arr[m] <= key)
            l = m+1;
        else
            r = m-1;
    }
    return l;
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
        int key;
        cin>>key;
        int l = lower(arr, 0, n-1, key);
        int r = upper(arr, 0, n-1, key);
        if(l==n || arr[l] != key )
        {
            cout<<"Not Present\n";
            continue;
        }
        cout<<key<<"-"<<(r-l)<<"\n";
    }
}
