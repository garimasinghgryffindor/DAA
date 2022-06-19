//  0/1 KNAPSACK
//DYNAMIC PROGRAMMING

#include <iostream>
#include <vector>
using namespace std;

int max(int x,int y)
{
    if(x>=y)
    return x;

    return y;
}

int knapsack(vector<int> wt,vector<int> val,int n,int K)
{
    int i,j;
    int sol[n+1][K+1];

    for(i=0 ; i<n+1 ; i++)
    {
        for(j=0 ; j<K+1 ; j++)
        {
            if(i==0 || j==0)
            {
                sol[i][j] = 0;
            }
            else if(wt[i-1]>j)
            {
                sol[i][j] = sol[i-1][j];
            }
            else
            {
                sol[i][j] = max(sol[i-1][j] , val[i-1]+sol[i-1][j-wt[i-1]]);
            }
        }
    }

    return sol[n][K];
}

int main()
{
    int n,weight,profit,K;

    cout<<"Enter the number of items:  ";
    cin>>n;
    vector <int> wt,val;
    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the weight and profit:  ";
        cin>>weight>>profit;
        wt.push_back(weight);
        val.push_back(profit);
    }
    cout<<"Enter the capacity of the sack:  ";
    cin>>K;

    int res = knapsack(wt,val,n,K);
    cout<<"Maximum profit:  "<<res<<endl;

    return 0;
}