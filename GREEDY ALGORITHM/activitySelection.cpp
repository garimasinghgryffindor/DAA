#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// activity selection problem
// greedy

int main()
{
    vector<pair<int,int> > activity;
    int start,end,n;
    int count=0;
    cout<<"enter the number of activities:  ";
    cin>>n;
    for(int i=0 ; i<n ; i++) {
        cout<<"enter the start and end time:   ";
        cin>>start>>end;
        activity.push_back(make_pair(end,start));
    }

    int currentEnd = -1;
    sort(activity.begin(), activity.end());

    for(int i=0 ; i<n ; i++) {
        if(activity[i].second > currentEnd) {
            count++;
            currentEnd = activity[i].first;
        }
    }

    cout<<"count:  "<<count<<endl;

    return 0;
}