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


// using overlapping tasks
// NAIVE APPROACH
static bool compare(vector<int>&a, vector<int>&b) {
   if(a[1] < b[1]) return true;
   if(a[1] > b[1]) return false;
   if(a[0] < b[0]) return true;
   return false;
}
int cpuTaskScheduler(int n, vector<vector<int>> arr) {
   sort(arr.begin(), arr.end(), compare);
   
   int res = 0;
   for(int i = 0; i < n; i++) {
      int count = 1;
      for(int j = i+1; j < n; j++) {
         if((arr[i][0]>arr[j][0] && arr[i][0]<arr[j][1])||(arr[j][0]>arr[i][0] && arr[j][0]<arr[i][1])) {
            count++;
         }
      }
      res = max(res, count);
   }

   return res;
}

