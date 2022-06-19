#include <iostream>
#include <string>
using namespace std;

int naive(string s, string p)
{
    int l1 = s.length() , l2 = p.length();
    int f=0;

    for(int i=0; i<=l1-l2 ; i++)
    {
        for(int j=0 ; j<l2 ; j++)
        {
            if(p[j]!=s[i+j])
            {
                f=1;
                break;
            }
        }
        if(f==0)
            return i;
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

    int index = naive(s,pattern);

    if(index==-1)
        cout<<"String does not match!\n";

    else
        cout<<"String matched !! at index  :  "<<index<<endl;
    return 0;
}