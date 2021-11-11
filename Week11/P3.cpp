// Partition equal subset sum

#include<iostream>
using namespace std;

bool checkSubset(int arr[], int n, int sum)
{
    bool t[n+1][sum+1]; // t[i][j] means whether there is a sum j possible in the array formed using i elements
    for(int i=0; i<sum+1; i++)
        t[0][i] = false;  // if elements are 0 and sum is > 0, cannot be find
    for(int i=0; i<n+1; i++)
        t[i][0] = true;  // if sum is 0, then always can be find
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<sum+1; j++)
        {
            if(arr[i-1] > j)
                t[i][j] = t[i-1][j];  // if element is > current sum, ignore it
            else
            {
                bool inc = t[i-1][j-arr[i-1]];  // including the element
                bool exc = t[i-1][j];  // excluding the element
                t[i][j] = inc || exc;  // if we get true in any case, we take the true case
            }
        }
    }
    return t[n][sum];
}

bool find(int arr[], int n)
{
    long long int tot = 0;
    for(int i=0; i<n; i++)
        tot += arr[i];
    if(tot & 1)
        return false;
    return checkSubset(arr, n, tot/2);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    if(find(arr, n))
        cout<<"yes\n";
    else
        cout<<"no\n";
}
