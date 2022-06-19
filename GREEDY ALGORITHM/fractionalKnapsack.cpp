//FRACTIONAL KNAPSACK
//GREEDY ALGORITHM TO MAXIMIZE PROFIT

// vector < pair <int      ,  pair < int ,     int > > >
//              profit/weight        profit     weight

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<pair<float , pair<int,int> > > viii;

bool compare(pair<int , pair<int,int> > a , pair<int , pair<int,int> > b)
{
    return a.first > b.first;
}

int main()
{
    viii knapsack;

    int capacity,profit,weight,n;
    int maxProfit=0 , weight_so_far=0;

    cout<<"Enter the number of materials:  ";
    cin>>n;
    cout<<"Enter the capapcity of knapsack:  ";
    cin>>capacity;
    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the Profit & Weight :  ";
        cin>>profit>>weight;
        knapsack.push_back(make_pair(profit/weight , make_pair(profit,weight)));
    }

    sort(knapsack.begin(),knapsack.end(),compare);

    for(int i=0 ; i<n ; i++)
    {
        if(knapsack[i].second.second <= capacity - weight_so_far)
        {
            weight_so_far+=knapsack[i].second.second;
            maxProfit+=knapsack[i].second.first;
        }
        else
        {
            int x = capacity - weight_so_far;
            weight_so_far = capacity;
            maxProfit+=x*knapsack[i].first;
        }

        if(weight_so_far==capacity)
        break;
    }

    cout<<"Max Profit from the knapsack:  "<<maxProfit<<endl;

    return 0;
}