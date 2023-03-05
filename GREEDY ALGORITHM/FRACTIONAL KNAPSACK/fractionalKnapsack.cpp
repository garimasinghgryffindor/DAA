#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int n,knapsack_capacity;
    float maxProfit=0;
    cout<<"Enter the number of objects:  ";
    cin>>n;
    vector<pair<float, pair<int,int> > > objects;
    for(int i=0 ; i<n ; i++) {
        int w,p;
        cout<<"Enter the weight of the object:  ";
        cin>>w;
        cout<<"Enter the profit associated with the object:  ";
        cin>>p;
        float ratio = (float)p/w;
        objects.push_back(make_pair(ratio, make_pair(p,w)));
    }

    cout<<"Enter the capacity of the knapsack:  ";
    cin>>knapsack_capacity;

    // sort the objects on the basis of the (profit per unit weight)
    sort(objects.rbegin(), objects.rend());

    for(int i=0 ; i<n ; i++) {
        auto object = objects[i];
        float r = object.first;
        int w = object.second.second;
        int p = object.second.first;
        if(w <= knapsack_capacity) {
            knapsack_capacity-=w;
            maxProfit += p;
        }
        else {
            maxProfit += r*knapsack_capacity;
            knapsack_capacity = 0;
        }

        if(knapsack_capacity == 0)
            break;
    }

    cout<<"\nmax profit:   "<<maxProfit<<endl;

    return 0;
}
