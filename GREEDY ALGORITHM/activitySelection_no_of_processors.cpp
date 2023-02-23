#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
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
    vector<bool> visited(n,false);
    int c=n;
    sort(activity.begin(), activity.end());

    cout<<c<<"  hello    ";

    while(c) {
        for(int i=0 ; i<n ; i++) {
            if(visited[i])
                continue;
            if(activity[i].second > currentEnd) {
                c--;
                cout<<c<<"    ";
                visited[i] = true;
                currentEnd = activity[i].first;
            }
        }
        count++;
        currentEnd = -1;
    }
    
    cout<<"\nmin no of processors required:   "<<count<<endl;

    return 0;
}