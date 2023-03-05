#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int n,profit,deadline;
    cout<<"enter the number of jobs:  ";
    cin>>n;

    vector<pair<int,int> > jobs;
    vector<bool> slots;

    int maxDeadline=0, maxProfit=0, count=0;

    for(int i=0 ; i<n ; i++) {
        cout<<"enter the profit :   ";
        cin>>profit;
        cout<<"enter the deadline:   ";
        cin>>deadline;
        jobs.push_back(make_pair(profit,deadline));
        maxDeadline = max(maxDeadline , deadline);
    }

    slots.resize(maxDeadline+1, false);
    sort(jobs.rbegin(), jobs.rend());

    for(auto job : jobs) {
        int deadline = job.second;
        int profit = job.first;

        while(slots[deadline]==true && deadline--);

        if(deadline != 0) {
            slots[deadline] = true;
            maxProfit += profit;
            count++;
        }
    }

    cout<<"max number of jobs:   "<<count<<endl;
    cout<<"max profit :   "<<maxProfit<<endl;

    return 0;
}
