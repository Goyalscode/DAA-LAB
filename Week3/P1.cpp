/* Given an unsorted array f integers, design an algorithm and a prgram to sort the array
   using insertion sort. Your program should be able to find the number of comparisons and
   shifts (shifts means total number of times the array elements are shifted from their place)
   required for sorting the array. */

#include<iostream>
using namespace std;

void insertionSort(int arr[], int n, int &comp, int &shifts)
{
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        int j  = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
            comp++;
            shifts++;
        }
        arr[j+1] = key;
        shifts++;
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
       int comp = 0, shifts = 0;
       insertionSort(arr, n, comp, shifts);
       for(int j=0; j<n; j++)
           cout<<arr[j]<<" ";
       cout<<"\ncomparisons = "<<comp<<"\n";
       cout<<"shifts = "<<shifts<<"\n";
   }
}
