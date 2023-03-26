    // using recursion
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       if(n==0 || W==0)
            return 0;
        
        if(wt[n-1] > W) 
            return knapSack(W,wt,val,n-1);
        
        // 2 possibilities. either include it or leave it
        
        return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W,wt,val,n-1));
    }





    // memoization
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int recur(int W,int wt[],int val[],int n,vector<vector<int>>&dp) {
        if(n < 0)
            return 0;
        
        if(dp[n][W] != -1)
            return dp[n][W];
        
        if(wt[n] > W) {
            return dp[n][W]=recur(W,wt,val,n-1,dp);
        } else {
            return dp[n][W]=max(val[n]+recur(W-wt[n],wt,val,n-1,dp), recur(W,wt,val,n-1,dp));
        }
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return recur(W,wt,val,n-1,dp);
    }





    // tabulation
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1,vector<int>(W+1));
       
       for(int i=0 ; i<=n ; i++) {
           for(int j=0 ; j<=W ; j++) {
               if(i==0 || j==0)
                    dp[i][j] = 0;
                else if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
           }
       }
       
       return dp[n][W];
    }
