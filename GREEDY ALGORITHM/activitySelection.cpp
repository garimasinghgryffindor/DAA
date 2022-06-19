//GREEDY ALGORITHM
//ACTIVITY SELECTION

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

void processors(vector<pair<int,int> >&activity,int n)
{
    vector<bool>status(n,false);
    int count=0;
    int current_end=-1;

    sort(activity.begin(),activity.end());

    for(int i=0 ; i<n ; i++)
    {
        current_end=-1;
        if(find(status.begin(),status.end(),false)==status.end())
        {
            break;
        }
        for(int j=0 ; j<n ; j++)
        {
            if(status[j]==false && activity[j].second>current_end)
            {
                current_end=activity[j].first;
                status[j]=true;
            }
        }
        count++;
    }

    cout<<"Minimum Number of processors required to complete all activities :  "<<count<<endl;
}

int main()
{
    vector <pair <int,int> > activity;
    int start,end,n;
    int count=0;

    cout<<"Enter the nunber of activities:  ";
    cin>>n;
    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the Start & End time:  ";
        cin>>start>>end;
        activity.push_back(make_pair(end,start));
    }

    sort(activity.begin(),activity.end());

    int currentEnd=-1;

    for(int i=0 ; i<n ; i++)
    {
        if(activity[i].second > currentEnd)
        {
            count++;
            currentEnd=activity[i].first;
        }
    }

    cout<<"Count:  "<<count<<endl;

    //IF MINIMUM NUMBER OF PROCESSORS TO BE USED TO COMPLETE ALL THE TASKS IS ASKED
    processors(activity,n);

    return 0;
}