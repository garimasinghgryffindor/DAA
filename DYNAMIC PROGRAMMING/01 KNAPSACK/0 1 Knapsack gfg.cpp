int recur(int W, int wt[], int val[], int i) {
     // take or not take
    if(i < 0) return 0;
    if(W <= 0) return 0;
    // either you will take nth item 
    int res = 0;
    if(W-wt[i] >= 0) {
        res = max(res, val[i] + recur(W-wt[i], wt, val, i-1));
    }
    
    res = max(res, recur(W, wt, val, i-1));
    return res;
 }
 
 int knapSack(int W, int wt[], int val[], int n) 
 { 
    // using recursion
    return recur(W, wt, val, n-1);
 }



