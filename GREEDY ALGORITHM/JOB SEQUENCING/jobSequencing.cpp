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


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
vector<int> JobScheduling(Job arr[], int n) 
    { 
        int maxDeadline = -1;
        int maxProfit = 0;
        int num = 0;
        for(int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        sort(arr, arr + n, [](Job a, Job b) { return a.profit > b.profit; });
        
        vector<bool>slots(maxDeadline+1, false);
        for(int i = 0; i < n; i++) {
            int deadline = arr[i].dead;
            int pro = arr[i].profit;
            
            while(slots[deadline]==true && deadline--);

            if(deadline != 0) {
                slots[deadline] = true;
                maxProfit += pro;
                num++;
            }
        }
        
        return {num, maxProfit};
    } 
