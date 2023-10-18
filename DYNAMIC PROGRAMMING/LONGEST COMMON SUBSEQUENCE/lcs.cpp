#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


// RECURSION
int lcs(int x, int y, string s1, string s2)
{
   if(x==0 || y==0)
       return 0;
   if(s1[x-1] == s2[y-1])
       return 1 + lcs(x-1,y-1,s1,s2);
   else 
       return max(lcs(x-1,y,s1,s2), lcs(x,y-1,s1,s2));
}


// MEMOIZATION
int lcsUtils(int x,int y,string s1,string s2,vector<vector<int> >&dp) {
   if(x==0 || y==0)
       return 0;
   if(dp[x][y] != -1)
       return dp[x][y];
        
   if(s1[x-1] == s2[y-1])
       return (dp[x][y] = 1 + lcsUtils(x-1,y-1,s1,s2,dp));
   else 
       return (dp[x][y] = max(lcsUtils(x-1,y,s1,s2,dp), lcsUtils(x,y-1,s1,s2,dp)));
}

int lcs(int x, int y, string s1, string s2)
{
   vector<vector<int> >dp(x+1,vector<int>(y+1, -1));
    
   return lcsUtils(x,y,s1,s2,dp);
}


// TABULATION
int lcs(int x, int y, string s1, string s2)
{
    vector<vector<int> >dp(x+1,vector<int>(y+1, 0));
    
    for(int i=0 ; i<x+1 ; i++) {
        for(int j=0 ; j<y+1 ; j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
            } else if( s1[i-1] == s2[j-1] ) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[x][y];
}

int main()
{
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";

    cout<<lcs(s1.length(),s2.length(),s1,s2)<<endl;

    return 0;
}
