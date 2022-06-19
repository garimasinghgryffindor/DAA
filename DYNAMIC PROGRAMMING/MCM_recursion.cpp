//MATRIX CHAIN MULTIPLICATION
//RECURSION

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MCM(vector <int> p , int i , int j)
{
    if(i==j)
        return 0;
    
    int k;
    int min=INT_MAX;
    int count;

    for(k=i ; k<j ; k++)
    {
        count = MCM(p,i,k) + MCM(p,k+1,j) + p[i-1]*p[k]*p[j];
        if(count<min)
        {
            min=count;
        }
    }

    return min;
}

int main()
{  
    int n , x , y; 
    cout<<"Enter the number of matrices:  ";
    cin>>n;

    vector <int> p(n+1);

    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the dimension : ";
        cin>>x>>y;
        p[i]=x;
        if(i==n-1)
        {
            p[i+1]=y;
        }
    }

    int count = MCM(p,1,n);

    cout<<"Minimum number of operations:  "<<count<<endl;

    return 0;
}