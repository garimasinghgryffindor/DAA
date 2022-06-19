//  KRUTH-MORRIS PRATT ALGORITHM
//  STRING MATCHING OR SEARCHING ALGO

#include <iostream>
#include <string>

using namespace std;

void lpsArray(int lps[] , string p , int n)
{
    int len = 0;
    lps[0] = 0;

    int i = 1;

    while(i<n)
    {
        if(p[i] == p[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }

            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMP(string s,string p)
{
    int m = s.length() , n = p.length();
    int lps[n];

    lpsArray(lps,p,n);

    int i=0 , j=0;

    while(i<m)
    {
        if(p[j] == s[i])
        {
            j++;
            i++;
        }

        if(j==n)
        {
            return i-j;
            j=lps[j-1];
        }
            
        else if(i<m && p[j]!=s[i])
        {
            if(j!=0)
            {
                j = lps[j-1];
            }
            else
                i = i+1;
        }
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

    int index = KMP(s,pattern);

    if(index==-1)
        cout<<"String does not match!\n";

    else
        cout<<"String matched !! at index  :  "<<index<<endl;
    return 0;
}

