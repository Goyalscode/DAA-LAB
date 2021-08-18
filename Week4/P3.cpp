/* Given an unsorted array of integers, design an algorithm and implement it using a program
   to find the Kth smallest or largest element in the array. (Worst case Time Complexity = O(n)) */


#include<iostream>
using namespace std;

void swap(int &n1, int &n2)
{
    int t = n1;
    n1 = n2;
    n2 = t;
}

int partition(int arr[], int l, int r)
{
    int i = l-1;
    int j= l;
    while(j < r)
    {
        if(arr[j] <= arr[r])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[r]);
    return i;
}

int kthElement(int arr[], int l, int r, int k, int n)
{
    if(l <= r)
    {
        int p = partition(arr, l, r);
        if(p == k-1)
            return arr[p];
        else if(p > k-1)
           return kthElement(arr, l, p-1, k, n);
        else
            return kthElement(arr, p+1, r, k, n);
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, k;
        cin>>n;
        int arr[n];
        for(int j=0; j<n; j++)
            cin>>arr[j];
        cin>>k;
        int ans = kthElement(arr, 0, n-1, k, n);
        if(ans == -1)
            cout<<"not present\n";
        else
            cout<<ans<<"\n";
    }
}
