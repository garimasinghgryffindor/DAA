//  SUBSET SUM PROBLEM
// DYNAMIC PROGRAMMING (TABULATION)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool SS(vector <int> s , int  n , int sum)
{
    // if(sum==0)
    //     return true;
    // if(n==0)
    //     return false;
    // if(sum < s[n-1])
    //     return SS(s,n-1,sum);
    // return SS(s,n-1,sum) || SS(s,n-1,sum-s[n-1]);

    bool subset[n+1][sum+1];

    for(int i=0 ; i<=n ; i++)
        subset[i][0] = true;
    
    for(int i=0 ; i<=sum ; i++)
        subset[0][i] = false;
    
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=sum ; j++)
        {
            if(j < s[i-1])
                subset[i][j] = subset[i-1][j];
            if(j >= s[i-1])
                subset[i][j] = subset[i-1][j] || subset[i-1][j-s[i-1]];
        }
    }

    return subset[n][sum];
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