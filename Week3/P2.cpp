/* Given an unsorted array of integers, design an algorithm and implement a program
   to sort this array using selection sort, Your program should also find the number
   of comparisons and number of swaps required.*/

#include<iostream>
using namespace std;

void selectionSort(int arr[], int n, int &comp, int &swaps)
{
    for(int i=0; i<n-1; i++)
    {
        int min = arr[i];
        int pos = i;
        for(int j=i+1; j<n; j++)
        {
            comp++;
            if(arr[j] < min)
            {
                min = arr[j];
                pos = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[pos] = temp;
        swaps++;
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
        selectionSort(arr, n, comp, swaps);
        for(int j=0; j<n; j++)
            cout<<arr[j]<<" ";
        cout<<"\ncomparisons = "<<comp<<"\n";
        cout<<"swaps = "<<swaps<<"\n";
    }
}
