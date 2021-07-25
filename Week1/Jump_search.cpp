/* For an array arr[] of size n and block (to be jumped) size m, search at the indexes arr[0], arr[m], arr[2m].....arr[km]
and so on. Once the interval (arr[km] < key < arr[ (k+1)m ]) is found, perform a linear search operation from the
index km to find the element key */

#include<iostream>
#include<cmath>
using namespace std;

int Jump_search(int arr[], int n, int s, int &comp)
{
    int l = 0, r = 0, i = 1;
    int jump = sqrt(n);
    while(r < n)
    {
        comp++;
        if(arr[r] == s)
            return 1;
        else if(arr[r] > s)
            break;
        l = r+1;
        r = r+jump;
    }
    r = min(r, n);
    while(l<r)
    {
        comp++;
        if(arr[l++] == s)
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
        int s;
        for(int j=0; j<n; j++)
            cin>>arr[j];
        cin>>s;
        int comp = 0;
        int st = Jump_search(arr, n, s, comp);
        if(st)
            cout<<"Present "<<comp<<"\n";
        else
            cout<<"Not Present "<<comp<<"\n";
    }
}
