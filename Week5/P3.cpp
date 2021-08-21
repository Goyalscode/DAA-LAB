/*  You have been given two sorted integer arrays of size m and n. Design an algorithm and
    implement it using a program to find list of elements which are common to both. (Time Complexity
    = O(m+n))  */


#include<iostream>
#include<vector>
using namespace std;

void common(int m, int n, int arr1[], int arr2[], vector<int> &ans)
{
    int i=0, j=0;
    while(i<m && j<n)
    {
        if(arr1[i] < arr2[j])
            i++;
        else if(arr2[j] < arr1[i])
            j++;
        else
        {
            ans.push_back(arr1[i++]);
            j++;
        }
    }
}

int main()
{
    int m, n;
    cin>>m;
    int arr1[m];
    for(int j=0; j<m; j++)
        cin>>arr1[j];
    cin>>n;
    int arr2[n];
    for(int j=0; j<n; j++)
        cin>>arr2[j];
    vector<int>ans;
    common(m, n, arr1, arr2, ans);
    int size = ans.size();
    if(size == 0)
        cout<<"No Common Elements\n";
    else
    {
        for(int j=0; j<size; j++)
            cout<<ans[j]<<" ";
        cout<<"\n";
    }
}
