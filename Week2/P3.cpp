/* Given a sorted array of non-negative integers, design an algorithm and implement it using a program to
   count the number of pairs of integers such that their difference is equal to a given key, K. */

#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int arr[n];
        unordered_map<int, int>ump;
        for(int j=0;j<n;j++)
            cin>>arr[j];
        int key;
        cin>>key;
        int tot = 0;
        for(int j=0;j<n;j++)
        {
            ump[arr[j]] = j+1;
            int diff1 = arr[j] - key;
            int diff2 = arr[j] + key;
            if(ump[diff1] != (j+1) && ump[diff1] != 0)
                tot++;
            if(ump[diff2] != (j+1) && ump[diff2] != 0)
                tot++;
        }
        cout<<tot<<"\n";
    }
}

