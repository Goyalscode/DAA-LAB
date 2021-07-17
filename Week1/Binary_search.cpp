#include<iostream>
using namespace std;

int Binary_search(int arr[], int n, int s, int *comp)
{
    int l = 0;
    int r = n-1;
    while(l <= r)
    {
        int m = l+(r-l)/2;
        *comp = *comp + 1;
        if(arr[m] == s)
            return 1;
        else if(arr[m] < s)
            l = m+1;
        else
            r = m-1;
    }
    return 0;
}

int main()
{
    freopen("Sorted_Input.txt", "r", stdin);
    freopen("Binary_Output.txt", "w", stdout);
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
        int st = Binary_search(arr, n, s, &comp);
        if(st)
            cout<<"Present "<<comp<<"\n";
        else
            cout<<"Not Present "<<comp<<"\n";
    }
}
