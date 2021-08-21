/*  Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
    implement it using a program to find which alphabet has maximum number of occurrences and print
    it. (Time Complexity = O(n)) (Hint: Use counting sort)  */


#include<iostream>
using namespace std;

int duplicates(char arr[], int n, char &maxalpha)
{
    int store[26] = {0};
    for(int i=0; i<n; i++)
        store[arr[i] % 97]++;
    int maxx = 0;
    for(int i=0; i<26; i++)
    {
        if(store[i] > 1)
        {
            if(store[i] > maxx)
            {
                maxx = store[i];
                maxalpha = i+97;
            }
        }
    }
    return maxx;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        char arr[n];
        for(int j=0; j<n; j++)
            cin>>arr[j];
        char maxalpha = '0';
        int ans = duplicates(arr, n, maxalpha);
        if(ans == 0)
            cout<<"No Duplicates Present\n";
        else
            cout<<maxalpha<<" - "<<ans<<"\n";
    }
}
