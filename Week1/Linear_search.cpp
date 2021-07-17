#include<iostream>
using namespace std;

int Linear_Search(int arr[], int n, int s, int* comp)
{
    for(int i=0; i<n; i++)
    {
        (*comp)++;
        if(arr[i] == s)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("Unsorted_Input.txt", "r", stdin);
    freopen("Linear_Output.txt", "w", stdout);
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
        int st = Linear_Search(arr, n, s, &comp);
        if(st)
            cout<<"Present "<<comp<<"\n";
        else
            cout<<"Not Present "<<comp<<"\n";
    }
}
