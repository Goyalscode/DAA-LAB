//  Activity Selection Problem

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct activity
{
    int start;
    int finish;
    int act_no;
};

bool comp(activity a, activity b)
{
    return a.finish < b.finish;
}

int select(vector<activity>arr, int n, int acts[])
{
    int c = 0;
    int curend = -1;
    sort(arr.begin(), arr.end(), comp);
    for(int i=0; i<n; i++)
    {
        if(arr[i].start >= curend)
        {
            curend = arr[i].finish;
            acts[c++] = (arr[i].act_no);
        }
    }
    return c;
}

int main()
{
    int n;
    cin>>n;
    vector<activity>arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i].start;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i].finish;
        arr[i].act_no = i+1;
    }
    int acts[n];
    int ans = select(arr, n, acts);
    cout<<"No. of non-conflicting activities : "<<ans<<"\n";
    cout<<"List of selected activities : ";
    for(int i=0; i<ans; i++)
    {
        if(i == ans-1)
            cout<<acts[i];
        else
            cout<<acts[i]<<", ";
    }
    cout<<"\n";
}

