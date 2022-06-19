#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int LIS(vector<pair<int,int> > v , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        v[i].second = 1;
    }

    int max=1;

    for(int i=1 ; i<n ; i++)
    {
        for(int j=0 ; j<i ; j++)
        {
            if(v[i].first > v[j].first && v[i].second < v[j].second + 1)
            {
                v[i].second = v[j].second + 1;
                if(v[i].second > max)
                    max = v[i].second;
            }
        }
    }

    return max;
}

int main()
{
    int n, x;
    cout << "Enter the number of elements:  ";
    cin >> n;

    vector<pair<int, int> > v(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element:  ";
        cin >> x;
        v[i].first=x;
    }

    int lis = LIS(v,n);

    cout<<"Longest Increasing Subsequence:  "<<lis<<endl;

    return 0;
}