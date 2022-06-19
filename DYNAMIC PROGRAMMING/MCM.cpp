//MATRIX CHAIN MULTIPLICATION
//DYNAMIC PROGRAMMING  (TABULATION   i.e; BOTTOM-UP)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MCM(vector <int> p , int n)
{
    int i,j,k,L,q;
    vector <vector<int> > m(n, vector <int> (n));

    for(i=1 ; i<n ; i++)
    {
        m[i][i]=0;
    }

    for(L=2 ; L<n ; L++)
    {
        for(i=1 ; i<n-L+1 ; i++)
        {
            j=i+L-1;
            m[i][j] = INT_MAX;

            for(k=i ; k<=j-1 ; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                
                if(q<m[i][j])
                    m[i][j]=q;
            }
        }
    }

    return m[1][n-1];
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

    int count = MCM(p,n+1);

    cout<<"Minimum number of operations:  "<<count<<endl;

    return 0;
}