//LONGEST INCREASING SUBSEQUENCE
//RECURSIVE

#include <iostream>
#include <vector>
using namespace std;

int _LIS(vector <int> v , int n,int *max)
{
    if(n==1)
        return 1;

    int i,res,max_ending_here=1;

    for(i=1 ; i<n ; i++)
    {
        res = _LIS(v,i,max);
        if(v[i-1]<v[n-1] && res+1>max_ending_here)
            max_ending_here = res+1;
    }

    if(*max<max_ending_here)
        *max=max_ending_here;

    return max_ending_here;
}

int LIS(vector <int> arr , int n)
{
    int max=1;
    _LIS(arr,n,&max);
    return max;
}

int main()
{   
    // 10 22 9 33 21 50 41 60
    int n , x;
    cout<<"Enter the number of elements:  ";
    cin>>n;
    vector <int> v(n);

    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the element:  ";
        cin>>x;
        v[i]=x;
    }

    int lis = LIS(v,n);

    cout<<lis<<endl;

    return 0;
}