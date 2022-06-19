//JOB SEQUENCING
//GREEDY ALGORITHM TO MAXIMIZE PROFIT
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<pair<int,int> > vii;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first > b.first;
}

int main()
{
    vii jobs;
    int n , profit, deadline;
    int max_deadline=-1;
    int max_profit=0 , count=0;

    cout<<"Enter the number of jobs:  ";
    cin>>n;

    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the profit and deadline:  ";
        cin>>profit>>deadline;
        jobs.push_back(make_pair(profit,deadline));

        if(deadline>max_deadline)
        {
            max_deadline=deadline;
        }
    }

    vector <int> fill(max_deadline,-1);

    sort(jobs.begin(),jobs.end(),compare);

    for(int i=0 ; i<n ; i++)
    {
        int dline = jobs[i].second;

        for(int j=dline-1 ; j>=0 ; j--)
        {
            //if it is not occupied with the job slot
            if(fill[j]==-1)
            {
                fill[j]=i;
                max_profit+=jobs[i].first;
                count++;
                break;
            }
        }
    }

    cout<<endl;
    cout<<"No of Jobs performed :  "<<count<<"  with the profit:  "<<max_profit<<endl;

    return 0;
}
