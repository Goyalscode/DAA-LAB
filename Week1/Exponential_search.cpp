/* Given an already sorted array of positive integers, design an algorithm
and implement it using a program to find whether a given key element is present in the sorted
array or not. For an array arr[] of size n, search at the indexes arr[0], arr[1], arr[2],
arr[4],.....,arr[2^k] and so on. Once the interval (arr[2^k ] < key < arr[2^(k+1)]) is found,
perform a linear search or binary search operation from the index 2^k to find the element key.
(Complexity = O(logn), where n is the number of elements need to be scanned for searching */

#include<iostream>
using namespace std;

int Binary_search(int arr[], int l, int r, int s, int &comp)
{
    while(l <= r)
    {
        int m = l+(r-l)/2;
        comp = comp + 1;
        if(arr[m] == s)
            return 1;
        else if(arr[m] < s)
            l = m+1;
        else
            r = m-1;
    }
    return 0;
}

int Exponential_search(int arr[], int n, int s, int &comp)
{

    if(arr[0] ==  s)
    {
        comp++;
        return 1;
    }
    comp++;
    int l = 1, r = 1;
    while(r < n)
    {
        comp++;
        if(arr[r] == s)
            return 1;
        else if(arr[r] > s)
            break;
        l = r+1;
        r = r*2;
    }
    return Binary_search(arr, l, min(r-1, n-1), s, comp);
}

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        int arr[n];
        int s;
        for(int j=0; j<n; j++)
            cin>>arr[j];
        cin>>s;
        int comp = 0;
        int st = Exponential_search(arr, n, s, comp);
        if(st)
            cout<<"Present "<<comp<<"\n";
        else
            cout<<"Not Present "<<comp<<"\n";
    }
}
