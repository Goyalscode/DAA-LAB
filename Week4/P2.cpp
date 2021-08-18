/* Given an unsorted array of integers, design an algorithm and implement it using a program
   to sort an array of elements by partitioning the array into two subarrays based on a pivot element
   such that one of the sub array holds values smaller than the pivot element while another sub array
   holds values greater than the pivot element. Pivot element should be selected randomly from the array.
   Your program should also find the number of comparisons and swaps required for sorting the array.  */


#include<iostream>
using namespace std;

void swap(int &i, int&j)
{
    int t = i;
    i = j;
    j = t;
}

int partition(int arr[], int l, int r, int &comp, int &swaps)
{
    int i = l-1;
    int j = l;
    int pivot = arr[r];
    while(j < r)
    {
        comp++;
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
        j++;
    }
    i++;
    swap(arr[i], arr[r]);
    swaps++;
    return i;
}

void quickSort(int arr[], int l, int r, int &comp, int &swaps)
{
    if(l < r)
    {
        int p = partition(arr, l, r, comp, swaps);
        quickSort(arr, l, p-1, comp, swaps);
        quickSort(arr, p+1, r, comp, swaps);
    }
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
        int comp = 0, swaps = 0;
        quickSort(arr, 0, n-1, comp, swaps);
        for(int j=0; j<n; j++)
            cout<<arr[j]<<" ";
        cout<<"\ncomparisons = "<<comp<<"\n";
        cout<<"swaps = "<<swaps<<"\n";
    }
}
