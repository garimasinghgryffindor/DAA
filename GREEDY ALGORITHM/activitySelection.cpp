// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <utility>
// using namespace std;

// // activity selection problem
// // greedy

// int main()
// {
//     vector<pair<int,int> > activity;
//     int start,end,n;
//     int count=0;
//     cout<<"enter the number of activities:  ";
//     cin>>n;
//     for(int i=0 ; i<n ; i++) {
//         cout<<"enter the start and end time:   ";
//         cin>>start>>end;
//         activity.push_back(make_pair(end,start));
//     }

//     int currentEnd = -1;
//     sort(activity.begin(), activity.end());

//     for(int i=0 ; i<n ; i++) {
//         if(activity[i].second > currentEnd) {
//             count++;
//             currentEnd = activity[i].first;
//         }
//     }

//     cout<<"count:  "<<count<<endl;

//     return 0;
// }





#include <bits/stdc++.h> 
bool static compare(pair<int,pair<int,int>> &m1, pair<int,pair<int,int>>& m2) {
         if (m1.first < m2.first) return true;
         else if (m1.first > m2.first) return false;
         else if (m1.second.second < m2.second.second) return true;
         return false;
      }

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int,pair<int,int>>> meetings;
    int n = start.size();
    for(int i=0 ; i<n ; i++) {
      meetings.push_back({end[i], {start[i], i+1}});
    }

    sort(meetings.begin(), meetings.end(),compare);

    int count = 0;
    vector<int>res;
    int currentEnd = -1;
    for(int i=0 ; i<n ; i++) {
        if(meetings[i].second.first > currentEnd) {
            count++;
            currentEnd = meetings[i].first;
            res.push_back(meetings[i].second.second);
        }
    }

    return res;
}
