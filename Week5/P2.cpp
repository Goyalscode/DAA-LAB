/*  Given an unsorted array of integers, design an algorithm and implement it using a program to
    find whether two elements exist such that their sum is equal to the given key element. (Time
    Complexity = O(n log n))  */


#include<iostream>
using namespace std;

void merge(int arr[], int l, int m , int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++)
        L[i] = arr[i+l];
    for(int i=0; i<n2; i++)
        R[i] = arr[m+1+i];
    int i=0, j=0, k=l;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while(i < n1)
        arr[k++] = L[i++];
    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void findpair(int arr[], int n, int key)
{
    int tot = 0;
    int i = 0, j = n-1;
    while(i < j)
    {
        if(arr[i] + arr[j] == key)
        {
            tot++;
            if(tot > 1)
                cout<<", ";
            cout<<arr[i]<<" "<<arr[j];
            i++;
            j--;
        }
        else if(arr[i] + arr[j] > key)
            j--;
        else
            i++;
    }
    if(tot == 0)
        cout<<"No Such Pair Exist\n";
    else
        cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n, key;
        cin>>n;
        int arr[n];
        for(int j=0; j<n; j++)
            cin>>arr[j];
        cin>>key;
        mergeSort(arr, 0, n-1);
        findpair(arr, n, key);
    }
}
