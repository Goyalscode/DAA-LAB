/* Given an unsorted array of integers, design an algorithm and implement it using a program
   to sort an array of elements by dividing the array into two subarrays and combininig these
   subarrays after sorting each one of them. Your program should also find the number of comparisons
   and inversions during sorting the array.  */


#include<iostream>
using namespace std;

void merge(int *arr, int l, int m , int r, int &comp, int &inv)
{
    int s1 = m-l+1;
    int s2 = r-m;
    int a1[s1], a2[s2];
    for(int i=0; i<s1; i++)
        a1[i] = arr[l+i];
    for(int i=0; i<s2; i++)
        a2[i] = arr[m+i+1];
    int i=0, j=0;
    int k = l;
    while(i<s1 && j<s2)
    {
        comp++;
        if(a1[i] <= a2[j])
        {
            arr[k] = a1[i];
            i++;
        }
        else
        {
            inv += s1-i;
            arr[k] = a2[j];
            j++;
        }
        k++;
    }
    while(i<s1)
        arr[k++] = a1[i++];
    while(i<s2)
        arr[k++] = a2[j++];
}

void mergeSort(int *arr, int l, int r, int &comp, int &inv)
{
    if(l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m, comp, inv);
        mergeSort(arr, m+1, r, comp, inv);
        merge(arr, l, m, r, comp, inv);
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
        int comp = 0, inv = 0;
        mergeSort(arr, 0, n-1, comp, inv);
        for(int j=0; j<n; j++)
            cout<<arr[j]<<" ";
        cout<<"\ncomparisons = "<<comp<<"\n";
        cout<<"Inversions = "<<inv<<"\n";
    }
}
