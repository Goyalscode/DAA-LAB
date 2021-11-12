/* Given a long list of tasks. Each task takes specific time to accomplish it and each task has a
   deadline associated with it. You have to design an algorithm and implement it using a program to
   find maximum number of tasks that can be completed without crossing their deadlines and also
   find list of selected tasks. */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct task
{
    int time;
    int deadline;
    int act_no;
};

bool comp(task a, task b)
{
    return a.deadline < b.deadline;
}

int find(vector<task>arr, int n, int tasks[])
{
    int c = 0;
    int curtime = 0;
    sort(arr.begin(), arr.end(), comp);
    for(int i=0; i<n; i++)
    {
        if(arr[i].time + curtime <= arr[i].deadline)
        {
            curtime += arr[i].time;
            tasks[c++] = arr[i].act_no;
        }
    }
    sort(tasks, tasks+c);
    return c;
}

int main()
{
    int n;
    cin>>n;
    vector<task>arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i].time;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i].deadline;
        arr[i].act_no = i+1;
    }
    int tasks[n];
    int ans = find(arr, n, tasks);
    cout<<"Max number of tasks = "<<ans<<"\n";
    cout<<"Selected task numbers : ";
    for(int i=0; i<ans; i++)
    {
        if(i == ans-1)
            cout<<tasks[i];
        else
            cout<<tasks[i]<<", ";
    }
    cout<<"\n";
}
