//LONGEST COMMON SUBSEQUENCE
//DYNAMIC PROGRAMMING

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int max(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    return y;
}

int lcs(string X,string Y,int m,int n)
{
    int sol[m+1][n+1];
    int i,j;
    for(i=0 ; i<=m ; i++)
    {
        for(j=0 ; j<=n ; j++)
        {
            if(i==0 || j==0)
                sol[i][j]=0;
            else if( X[i-1] == Y[j-1] )
                sol[i][j] = 1 + sol[i-1][j-1];
            else
                sol[i][j] = max(sol[i-1][j] , sol[i][j-1]);
        }
    }

    return sol[m][n];
}


int main()
{
    string x,y;
    cout<<"Enter string 1 : ";
    cin>>x;
    cout<<"Enter string 2 : ";
    cin>>y;

    int l1 = x.length() , l2 = y.length();

    int count = lcs(x,y,l1,l2);
    cout<<"Longest Common Substring length :   "<<count<<endl;

    return 0;
}