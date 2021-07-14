/* Question : Given an array of nonnegative integers, design a linear algorithm and implement it using
   a program to find whether a given key element is present in the array or not. Also, find the total
   number of comparisons for each input case. (Time Complexity = O(n), where n is the size of input). */


#include<iostream>
using namespace std;
int main()
{
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        int s;
        cin>>s;
        int loc = -1;
        int comp = 0;
        for(int i=0; i<n; i++)
        {
            comp++;
            if(arr[i] == s)
            {
                loc = i;
                break;
            }
        }
        cout<<loc<<" "<<comp<<"\n";
    }
}
