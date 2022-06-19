//  SUBSET SUM PROBLEM
// RECURSIVE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool SS(vector <int> s , int  n , int sum)
{
    if(sum==0)
        return true;
    if(n==0)
        return false;
    if(sum < s[n-1])
        return SS(s,n-1,sum);
    return SS(s,n-1,sum) || SS(s,n-1,sum-s[n-1]);
}

int main()
{
    int n,x;
    cout<<"Enter the number if elements:  ";
    cin>>n;
    vector<int> arr(n);

    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the element:  ";
        cin>>x;
        arr[i] = x;
    }

    cout<<"Enter the subset sum:  ";
    int sum;
    cin>>sum;

    bool subsetSum = SS(arr,n,sum);

    cout<<subsetSum<<endl;

    return 0;
}