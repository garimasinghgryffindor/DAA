//  RABIN-KARP ALGORITHM
//  STRING MATCHING OR SEARCHING ALGORITHM

#include <iostream>
using namespace std;

int power(int m , int n)
{
    int prod = 1;
    for(int i=0 ; i<n ; i++)
    {
        prod*=m;
    }

    return prod;
}

int rabinK(string s,string p)
{
    int m = s.length() , n = p.length();
    int f=0;

    int hash_p=0 , hash_s=0;

    for(int i=0 ; i<n ; i++)
    {
        hash_p+=power(26,n-i-1)*(p[i]-97);
        hash_s+=power(26,n-i-1)*(s[i]-97);
    }

    int d = power(26,n-1);

    int x = d*(s[0]-97);

    for(int i=0 ; i<=m-n ; i++)
    {
        if(hash_p==hash_s)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(p[j]!=s[i+j])
                {                                     //  aabacddffhk
                    f=1;                              //  acddf
                    break;
                }
            }
            
            if(f==0)
                return i;
        }

        hash_s = hash_s - x;
        hash_s = 26*hash_s + 1*(s[n+i]-97);
        x = d*(s[i+1]-97);
        f=0;
    }

    return -1;
}

int main()
{
    string s, pattern;
    cout<<"Enter a string:  ";
    cin>>s;
    cout<<"Enter a patten:  ";
    cin>>pattern;

    int index = rabinK(s,pattern);

    if(index==-1)
        cout<<"String does not match!\n";

    else
        cout<<"String matched !! at index  :  "<<index<<endl;
    return 0;
}