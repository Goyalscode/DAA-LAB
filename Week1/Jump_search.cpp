#include<iostream>
using namespace std;

int Jump_search(int arr[], int n, int s, int *comp)
{
    int l = 0, r = 0, i = 1;
    while(r < n)
    {
        (*comp)++;
        if(arr[r] == s)
            return 1;
        else if(arr[r] > s)
            break;
        else
        {
            l = r+1;
            if(l >= n)
                return -1;
            i = i*2;
            r = i;
            if(r >= n)
                r = n-1;
        }
    }
    while(l<r)
    {
        (*comp)++;
        if(arr[l++] == s)
            return 1;
    }
    return 0;
}

int main()
{
    freopen("Sorted_Input.txt", "r", stdin);
    freopen("Jump_Output.txt", "w", stdout);
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
        int st = Jump_search(arr, n, s, &comp);
        if(st)
            cout<<"Present "<<comp<<"\n";
        else
            cout<<"Not Present "<<comp<<"\n";
    }
}
