/* Given an unsorted array of elements, design an algorithm and implement it using a program to
   find whether majority element exists or not. Also find median of the array. A majority element is
   an element that appears more than n/2 times, where n is the size of array.  */

#include<iostream>
#include<algorithm>
using namespace std;

bool findMaj(int arr[], int n , double& med)
{
    sort(arr, arr+n);
    if(n & 1)
        med = arr[n/2];
    else
        med = (arr[n/2] + arr[(n-1)/2]) / 2.0;
    int max_count = INT_MIN;
    int count = 1;
    for(int j=1; j<n; j++)
    {
        if(arr[j] == arr[j-1])
            count++;
        else
        {
            max_count = max(max_count, count);
            count = 1;
        }
    }
    max_count = max(max_count, count);
    if(max_count > (n/2))
        return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    double med;
    bool maj = findMaj(arr, n, med);
    if(maj == false)
        cout<<"no\n";
    else
        cout<<"yes\n";
    printf("%.1lf\n", med);
}
