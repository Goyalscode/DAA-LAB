//  Fractional Knapsack Problem

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return (double)a.first.second/(double)a.first.first > (double)b.first.second/(double)b.first.first;
}

double fractionalKnapsack(vector<pair<pair<int, int>, int>>& items, int n, int Weight, int& inc)
{
    int W = Weight;
    sort(items.begin(), items.end(), comp);
    double p = 0.0;
    for(int i=0; i<n; i++)
    {
        if(W >= items[i].first.first)
        {
            W -= items[i].first.first;
            p += items[i].first.second;
            inc++;
        }
        else
        {
            double v_w = (double)items[i].first.second/(double)items[i].first.first;
            p += W * v_w;
            inc++;
            break;
        }
    }
    return p;
}

int main()
{
    int n;
    cin>>n;
    vector<pair<pair<int, int>, int>>items(n);
    for(int i=0; i<n; i++)
    {
        cin>>items[i].first.first;
        items[i].second = i+1;
    }
    for(int i=0; i<n; i++)
        cin>>items[i].first.second;
    int W;
    cin>>W;
    int inc = 0;
    double ans = fractionalKnapsack(items, n, W, inc);
    printf("Maximum value : %.2lf\n", ans);
    cout<<"item-weight\n";
    int sum = 0;
    for(int i=0; i<inc; i++)
    {
        cout<<items[i].second<<"-";
        if(i == inc-1)
            cout<<W-sum<<"\n";
        else
        {
            cout<<items[i].first.first<<"\n";
            sum += items[i].first.first;
        }
    }
}
