/* Given an unsorted array of positive integers, design an algorithm and implement it
   using a program to find whether there are any duplicate elements in the array or
   not. (use sorting) (Time Complexity = O(n log n)). */

#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int s1 = m-l+1;
    int s2 = r-m;
    int a1[s1], a2[s2];
    for(int i=0; i<s1; i++)
        a1[i] = arr[l+i];
    for(int i=0; i<s2; i++)
        a2[i] = arr[m+1+i];
    int k = l, i = 0, j = 0;
    while(i<s1 && j<s2)
    {
        if(a1[i] < a2[j])
            arr[k++] = a1[i++];
        else
            arr[k++] = a2[j++];
    }
    while(i < s1)
    {
        arr[k++] = a1[i++];
    }
    while(j < s2)
    {
        arr[k++] = a2[j++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int checkDuplicate(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        if(arr[i] == arr[i-1])
            return 1;
    }
    return 0;
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
        for(int j=0; j<n; j++)
            cin>>arr[j];
        mergeSort(arr, 0, n-1);
        int st = checkDuplicate(arr, n);
        if(st)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
